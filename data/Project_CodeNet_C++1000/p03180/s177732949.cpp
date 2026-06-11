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

const ll mod=1e9+7;

ll a[20][20];
ll cost[1<<16];
ll dp[1<<16];

int main()
{
    ll n;
    cin >> n;
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
        }
    }
    dp[0]=0;
    for(ll s=1;s<(1<<n);s++){
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                if((s>>i)%2==0) continue;
                if((s>>j)%2==0) continue;
                cost[s]+=a[i][j];
            }
        }
    }
    //cout << cost[(1<<n)-1] << endl;
    for(ll s=1;s<(1<<n);s++){
        for(ll t=s;t>0;t=(t-1)&s){
            dp[s]=max(dp[s],dp[s-t]+cost[t]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
} 