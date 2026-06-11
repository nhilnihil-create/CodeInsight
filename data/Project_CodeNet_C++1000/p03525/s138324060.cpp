#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N_MAX = 50;
int main()
{
  int n,m=0,mm,t=0,b=-1,i,j,res=0;
  int d[N_MAX];
  bool h[24],h0[24];
  vector<int> v;
  cin >> n;
  for(i=0;i<n;i++)
    cin >> d[i];
  sort(d,d+n);
  fill(h0,h0+24,0);
  h0[0]=1;
  for(i=0;i<n;i++){
    if(d[i]==b){
      t++;
    }else{
      b=d[i];
      t=1;
    }
    if(b==0 || b==12){
      if(b==0 || t>=2){
        cout << "0" << endl;
        return 0;
      }
      h0[b]=1;
    }else if(t==1){
      v.push_back(b);
    }else if(t==2){
      v.pop_back();
      h0[b]=1;
      h0[24-b]=1;
    }else if(t>=3){
      cout << "0" << endl;
      return 0;
    }
  }
  m=v.size();
  mm=1<<m;
  for(i=0;i<mm;i++){
    t=i;
    copy(h0,h0+24,h);
    for(j=0;j<m;j++){
      if(t%2==1){
        h[v[j]]=1;
      }else{
        h[24-v[j]]=1;
      }
      t>>=1;
    }
    b=0;
    t=24;
    for(j=1;j<24;j++)
      if(h[j]==1){
        t=min({j-b,b+24-j,t});
        b=j;
      }
    t=min({j-b,b+24-j,t});
    res=max(res,t);
  }
  cout << res << endl;
  return 0;
}