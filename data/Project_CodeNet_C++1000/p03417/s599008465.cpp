#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main() {
ll N;
  ll M;
  
  cin >>N>>M;
  if(N<=M) {
  if((N==1)&&(M==1)) {
    cout<<1<<endl;
  }
else if((N==1) &&(M!=1)) {
  cout<<M-2<<endl;
}
  else {
    cout<<(N-2)*(M-2)<<endl;
  }
  }
  
  
  
  
  
  else if(M<N) {
    if((M==1)&&(N!=1)) {
      cout<<N-2<<endl;
    }
    else {
      cout<<(N-2)*(M-2)<<endl;
    }
  }
    
    
    
    
    
    
    
    
    
}
  
