#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e18;

int main()
{
    ll n,m;
    ll d[9]={2,5,5,4,5,6,3,7,6};
    cin >> n >> m;
    vector<pll> a(m);
    rep(i,m){
        cin >> a[i].fi;
        a[i].se=d[a[i].fi-1];
    }
    sort(a.rbegin(),a.rend());
    vector<ll> dp(n+1,-1);
    dp[0]=0;
    rep(i,n+1){
        if(dp[i]!=-1){
            rep(j,m){
                if(i+a[j].se<=n){
                    dp[i+a[j].se]=max(dp[i+a[j].se],dp[i]+1);
                }
            }
        }
    }
    ll match=n,remain=dp[n];
    string ans="";
    while(match>0){
        rep(i,m){
            if(match>=a[i].se && dp[match-a[i].se]==remain-1){
                match-=a[i].se;
                remain--;
                string c=to_string(a[i].fi);
                ans+=c;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
} 