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

ll dp[3300][3300];
ll dp_sum[3300][3300];

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    dp[0][0]=1;
    for(ll i=1;i<n;i++){
        for(ll j=0;j<=i;j++){
            dp_sum[i-1][j]=dp[i-1][j];
            if(j-1>=0) dp_sum[i-1][j]+=dp_sum[i-1][j-1];
            dp_sum[i-1][j]%=mod;
        }
        for(ll j=0;j<=i;j++){
            if(s[i-1]=='<'){
                if(j-1>=0){
                    dp[i][j]=dp_sum[i-1][j-1];
                }
            }
            else{
                dp[i][j]=dp_sum[i-1][i-1];
                if(j-1>=0) dp[i][j]-=dp_sum[i-1][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    ll ans=0;
    rep(i,n){
        ans+=dp[n-1][i];
        ans%=mod;
    }
    if(ans<0) ans+=mod;
    ans%=mod;
    cout << ans << endl;
    return 0;
} 