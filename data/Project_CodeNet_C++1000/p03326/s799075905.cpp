#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
int n,m;
ll x[1010],y[1010],z[1010];
ll calc(vector<bool> const& status){
  ll res=0;
  vector<ll> eat;
  rep(i,n){
    ll buf=0;
    if(status[0])buf+=x[i];
    else buf-=x[i];
    if(status[1])buf+=y[i];
    else buf-=y[i];
    if(status[2])buf+=z[i];
    else buf-=z[i];
    eat.push_back(buf);
    //else eat.push_back(0);
  }
  sort(ALL(eat));reverse(ALL(eat));
  rep(i,m){
    res+=eat[i];
  }
  return res;
}
ll solve(vector<bool> status,int cur){
  ll res=0;
  if(cur==4){
    return calc(status);
  }
  else{
    res=solve(status,cur+1);
    status[cur]=true;
    res=max(res,solve(status,cur+1));
  }
  return res;
}
signed main(){
  cin>>n>>m;
  rep(i,n){
    cin>>x[i]>>y[i]>>z[i];
  }
  vector<bool> status(4,false);
  ll res=solve(status,0);
  cout<<res<<endl;
  return 0;
}
