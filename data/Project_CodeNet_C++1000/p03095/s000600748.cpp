#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    rep(i, n)mp[s[i]]++;
    int m = mp.size();
    vector<vector<ll>> dp(m+1, vector<ll>(2, 0));
    dp[0][0] = 1;
    ll mod = 1000000007;
    int cnt = 0;
    for(auto p : mp){
        ll c = p.second;
        dp[cnt+1][0] = (dp[cnt][0] + dp[cnt][1]) % mod;
        dp[cnt+1][1] = (dp[cnt][0] + dp[cnt][1]) % mod * c % mod;
        cnt++;
    }
    ll ans = (dp[m][0] + dp[m][1] - 1 + mod) % mod;
    cout << ans << endl;
}