#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    ll n;cin>>n;
    vector<ll>a(1LL<<n);
    rep(i,1LL<<n){
        cin>>a[i];
    }
    vector<pll>dp(1LL<<n);
    rep(i,1LL<<n){
        dp[i]=mp(a[i],-1);
    }
    rep(j,n){
        rep(i,1LL<<n){
            if(i&(1LL<<j)){
                pll a=dp[i];
                pll b=dp[i-(1LL<<j)];
                if(a.first<b.first){
                    a.second=max(a.first,b.second);
                    a.first=b.first;
                }else{
                    a.second=max(a.second,b.first);
                }
                dp[i]=a;
            }
        }
    }
    ll ans=0;
    REP(i,1,1LL<<n){
        ans=max(ans,dp[i].first+dp[i].second);
        cout<<ans<<endl;
    }
}