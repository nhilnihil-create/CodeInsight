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
    ll n,k;
    cin >> n >> k;
    ll val=k;
    vector<ll> a(n),b(45);
    rep(i,n){
        cin >> a[i];
        rep(j,45){
            if((a[i]>>j)%2==1) b[j]++;
        }
    }
    vector<vector<ll>> dp(46,vector<ll>(2)); //1→ぴったり 0→真に小さい
    vector<ll> p(45);
    ll v=1;
    rep(i,45){
        p[i]=v;
        v*=2;
    }
    ll cnt=0;
    while(val!=0){
        cnt++;
        val/=2;
    }
    ll ans=0;
    rep(i,45){
        if(i>=cnt){
            ans+=b[i]*p[i];
        }
    }
    rep(i,cnt){
        ll move=cnt-1-i;
        if((k>>move)%2==1){
            if(2*b[move]>n){
                dp[i+1][0]=max(dp[i][0]+b[move]*p[move],dp[i][1]+b[move]*p[move]);
                dp[i+1][1]=dp[i][1]+(n-b[move])*p[move];
            }
            else{
                if(dp[i][0]!=0){
                    dp[i+1][0]=dp[i][0]+(n-b[move])*p[move];
                }
                dp[i+1][0]=max(dp[i+1][0],dp[i][1]+b[move]*p[move]);
                dp[i+1][1]=dp[i][1]+(n-b[move])*p[move];
            }
        }
        else{
            if(2*b[move]>n){
                if(dp[i][0]!=0){
                    dp[i+1][0]=dp[i][0]+b[move]*p[move];
                }
                dp[i+1][1]=dp[i][1]+b[move]*p[move];
            }
            else{
                if(dp[i][0]!=0){
                    dp[i+1][0]=dp[i][0]+(n-b[move])*p[move];
                }
                dp[i+1][1]=dp[i][1]+b[move]*p[move];
            }
        }
        //cout << dp[i+1][0] << " " << dp[i+1][1] << endl;
        
    }
    cout << ans+max(dp[cnt][0],dp[cnt][1]) << endl;
    return 0;
} 