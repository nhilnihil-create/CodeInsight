#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int N_MAX = 100000;
typedef pair<int,int> P; // t,c
typedef pair<P,int> PP; // s,c,t
int main()
{
  int n,c,s,t,cc,i,j,res;
  P pt;
  vector<P> v;
  PP p[N_MAX];
  priority_queue<P,vector<P>,greater<P>> q;
  cin >> n >> c;
  for(i=0;i<n;i++)
    cin >> p[i].first.first >> p[i].second >> p[i].first.second;
  sort(p,p+n);
  q.push(P(p[0].second,p[0].first.second));
  for(i=1;i<n;i++){
    s=p[i].first.first;
    t=p[i].second;
    cc=p[i].first.second;
    if(!v.empty()){
      pt=v[0];
      if(pt.first<s || pt.first==s&&pt.second==cc){
        v.erase(v.begin());
        pt=P(t,cc);
        q.push(pt);
        continue;
      }else if(pt.first==s&&pt.second<cc){
        for(j=1;j<v.size();j++){
          pt=v[j];
          if(pt.first>s || pt.first==s&&pt.second>=cc)
            break;
        }
        if(pt.first==s&&pt.second==cc){
          v.erase(v.begin()+j);
          pt=P(t,cc);
          q.push(pt);
          continue;
        }else if(pt.first>s || pt.first==s&&pt.second>cc){
          pt=P(t,cc);
          q.push(pt);
          continue;
        }// else v.empty()の場合に合流
      }else{
        pt=P(t,cc);
        q.push(pt);
        continue;
      }
    }
    pt=q.top();
    if(pt.first<s || pt.first==s&&pt.second==cc){
      q.pop();
    }else if(pt.first==s&&pt.second<cc){
      while(pt.first==s&&pt.second<cc&&q.size()>1){
        q.pop();
        v.push_back(pt);
        pt=q.top();
      }
      if(pt.first==s&&pt.second==cc){
        q.pop();
      }
    }
    pt=P(t,cc);
    q.push(pt);
  }
  res=v.size()+q.size();
  cout << res << endl;
  return 0;
}