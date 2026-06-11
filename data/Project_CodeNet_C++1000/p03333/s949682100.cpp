#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);++i)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;--i)
#define rep1(i,n) for(int (i)=1;(i)<=(n);++i)
#define rrep1(i,n) for(int (i)=(n);(i)>=1;--i)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;

priority_queue<LP> qr;
priority_queue<LP,vector<LP>,greater<LP> >  ql;
ll N;
ll L[100000],R[100000];
ll used[100000];
ll ans = 0;

ll calc(ll b){
  ll res = 0;
  ll pos = 0;
  rep(i,N) used[i]=0;
  while(!ql.empty()) ql.pop();
  while(!qr.empty()) qr.pop();
  rep(i,N){
    ql.push(LP(R[i],i));
    qr.push(LP(L[i],i));
  }
  rep(i,N){

    LP p;
    if(b==1){
        for(;;){
        //while(1){
          p = ql.top();
          ql.pop();
          if(!used[p.sc]){
            used[p.sc]=1;
            break;
          }
        }
        if(R[p.sc] < pos){
          res += abs(R[p.sc] - pos);
          pos = R[p.sc];
        }
        else if(pos <= L[p.sc]){
          res += abs(L[p.sc] - pos );
          pos = L[p.sc];
        }
        b = 0;
    }
    else{
      while(1){
        p = qr.top();
        qr.pop();
        if(!used[p.sc]){
          used[p.sc]=1;
          break;
        }
      }
      if(L[p.sc] > pos){
        res += abs(L[p.sc] - pos);
        pos = L[p.sc];
      }
      else if(pos >= R[p.sc]){
        res += abs(R[p.sc] - pos );
        pos = R[p.sc];
      }
      b = 1;
    }
  }
  return res + abs(pos);
}

int main()
{
  cin>>N;
  rep(i,N) cin>>L[i]>>R[i];
  cout<<max(calc(0),calc(1))<<endl;
}
