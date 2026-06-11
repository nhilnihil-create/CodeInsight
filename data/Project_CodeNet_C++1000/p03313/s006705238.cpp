//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;

#define all(a) begin(a),end(a)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
const int mod=998244353;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int mul(int a,int b){
  return ((a)*1ll*(b))%mod;
}
 
void add(int &a,int b){
  a+=b;
  if(a>=mod)a-=mod;
}
 
int sub(int a,int b){
  a-=b;
  if(a<0){
    a+=mod;
  }
  return a;
}
 
int powz(int a,int b){
  int res=1;
  while(b){
    if(b&1){
      res=mul(res,a);
    }
    b/=2;
    a=mul(a,a);
  }
  return res;
}
 
template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
  input>>x.F>>x.S;
  return input;
}
 
template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
    output<<i<<' ';
  return output;
}

void getvec(vector<pair<int,int>>&a){
  for(int i=0;i<a.size();i++){
    cin>>a[i].F;
    a[i].S=i;
  }
}
 
const int N=1000002;

pair<int,int> dp[N];
bool vis[N];
vector<int>zz;

void dfs(int ind,int val){
  if(vis[ind]){
    return;
  }
  if(dp[ind].S!=-1){
    return;
  }
  vis[ind]=true;
  zz.pb(ind);
  if(dp[ind].F<=val){
    dp[ind].S=dp[ind].F;
    dp[ind].F=val;
  }
  else if(dp[ind].S<=val){
    dp[ind].S=val;
  }
  for(int i=0;i<19;i++){
    if((ind>>i)&1){
    }
    else{
      dfs(ind^(1<<i),val);
    }
  }
}

void solve(){
  int n;
  cin>>n;
  for(int i=0;i<(1<<n);i++){
    dp[i].F=dp[i].S=-1;
  }
  vector<pair<int,int>>a(1<<n);
  getvec(a);
  sort(all(a));
  int ans=0;
  for(int i=(1<<n)-1;i>=0;i--){
    dfs(a[i].S,a[i].F);
    for(auto j:zz){
      vis[j]=false;
    }
    zz.clear();
  }
  for(int i=1;i<(1<<n);i++){
    ans=max(ans,dp[i].F+dp[i].S);
    cout<<ans<<'\n';
  }
 
}
 
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc=1;
  //cin>>tc;
  for(int _=0;_<tc;_++){
    // cout<<"Case #"<<_+1<<": ";
    solve();
    if(_!=tc-1){
      cout<<'\n';
    }
  }
}
