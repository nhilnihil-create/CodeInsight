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

int main(){
    string s;
    cin >> s;
    ll n=s.length();
    vector<vector<ll>> dp(n+1,vector<ll>(4));
    dp[0][0]=1;
    rep(i,n){
        if(s[i]=='?'){
            rep(k,3){
                rep(j,4){
                    dp[i+1][j]+=dp[i][j];
                    dp[i+1][j]%=mod;
                }
                dp[i+1][k+1]+=dp[i][k];
                dp[i+1][k+1]%=mod;
            }
        }
        if(s[i]=='A'){
            rep(j,4){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=mod;
            }
            dp[i+1][1]+=dp[i][0];
            dp[i+1][1]%=mod;
        }
        if(s[i]=='B'){
            rep(j,4){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=mod;
            }
            dp[i+1][2]+=dp[i][1];
            dp[i+1][2]%=mod;
        }
        if(s[i]=='C'){
            rep(j,4){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=mod;
            }
            dp[i+1][3]+=dp[i][2];
            dp[i+1][3]%=mod;
        }
    }
    cout << dp[n][3] << endl;
    return 0;
} 