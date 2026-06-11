#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

void chmax2(Pll &a,Pll b){
    if(a.fi<b.fi){
        a.se=max(a.fi,b.se);
        a.fi=b.fi;
    }else{
        a.se=max(a.se,b.fi);
    }
}

const ll INF = 1e12;
signed main(){
    int n; cin >> n;
    vector<ll> a(1<<n);
    vector<Pll> dp(1<<n);
    rep(i,1<<n){
        cin >> a[i];
        dp[i]={a[i],-INF};
    }
    rep(i,n){
        rep(j,1<<n){
            if(j&(1<<i)){
                chmax2(dp[j],dp[j^(1<<i)]);
            }
        }
    }
    ll res=-INF;
    rep(i,1<<n){
        ll ans=dp[i].fi+dp[i].se;
        chmax(res,ans);
        if(i) cout << res << endl;
    }
}
