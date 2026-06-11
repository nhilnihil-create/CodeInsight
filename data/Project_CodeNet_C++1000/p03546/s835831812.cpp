#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
struct edge {
    int to, cost;
};

int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}

auto factor(int n){
  map<int,int>res;
  for(int i=2;i*i<=n;i++){
      for(; n%i==0;n/=i) res[i]++;
  }
  if(n>1)res[n]++;
  return res;
}
////////////////////////////////////////////////////////////
signed main() {
  int h,w;
  cin>>h>>w;
  int c[10][10];
  rep(i,10)rep(j,10){cin>>c[i][j];}
  vector<int>d(10);
  rep(i,10)d[i]=c[i][1];
  rep(i,10){
    if(i!=1){
      vector<int>v(0);
      rep(j,10){
        if(j!=i)v.push_back(j);
      }

      do{
        int t=0;
        for(int k=0;k<9;k++){
          if(k==0) {
            t+=c[i][v[k]];
            if(v[0]==1)continue;
          }
          if(k!=0){
            t+=c[v[k-1]][v[k]];
            if(v[k]==1){
              d[i]=min(d[i],t);
            }
          }
          if(t>d[i])break;
        }
      }while(next_permutation(v.begin(),v.end()));
    }
  }
  int ans=0;
    rep(i,h){
      rep(j,w){
        int a;
        cin>>a;
        if(a!=1&&a!=-1){
          ans+=d[a];
        }
      }
    }
    cout<<ans<<endl;

}
