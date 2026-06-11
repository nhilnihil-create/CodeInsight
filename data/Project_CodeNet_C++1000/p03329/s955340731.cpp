#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
#define all(v) v.begin(), v.end()
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
    


ll bs(ll n , vector<ll> &v){
    ll ok = -1;
    ll ng = v.size();
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng)/2;
        if(v[mid] <= n)ok = mid;
        else ng = mid;
    }
    return v[ok];
}

//ミョ(-ω- ?)
int main() {
    vector<ll> six;
    ll b = 1;
    while(b < 100000){
        b *= 6;
        six.emplace_back(b);
    }
    sort(all(six));
    vector<ll> nine;
    b = 1;
    while(b < 100000){
        b *= 9;
        nine.emplace_back(b);
    }
    sort(all(nine));
    ll n;cin >> n;
    static vector<vector<ll>> dp(100010,vector<ll>(3,INF));//dp[i][0] = 1を選ぶ,[1] = 6^n,[2] = 9^n
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    repp(i,1,n+1){
        dp[i][0] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + 1;
        if(i >= 6){
            dp[i][1] = min({dp[i - bs(i,six)][0],dp[i - bs(i,six)][1],dp[i - bs(i,six)][2]})+1;
        }
        if(i >= 9){
            dp[i][2] = min({dp[i - bs(i,nine)][0],dp[i - bs(i,nine)][1],dp[i - bs(i,nine)][2]})+1;
        }
    }
    cout << min({dp[n][0],dp[n][1],dp[n][2]}) << "\n";
    return 0;
}