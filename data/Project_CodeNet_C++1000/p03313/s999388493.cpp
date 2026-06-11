#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

void chmax(P &a,P b) {
  if (a.ft<b.ft) a.sc=max(a.ft,b.sc), a.ft=b.ft;
  else a.sc=max(a.sc,b.ft);
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    cin>>n;
    V<ll> a((1<<n));
    V<P> dp(1<<n);
    rep(i,(1<<n)){
        cin>>a[i];
        dp[i]=make_pair(a[i],-INF);
    }
    rep(j,n){
        rep(i,(1<<n)){
            if(i>>j&1){
                chmax(dp[i],dp[i^(1<<j)]);
            }
        }
    }
    ll ans=-INF;
    rep(i,(1<<n)){
        ll tmp=dp[i].ft+dp[i].sc;
        ans=max(ans,tmp);
        if(i) cout<<ans<<'\n';
    }
}