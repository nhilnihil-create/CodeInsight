#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int N; cin >> N;
    vector<ll> dp(N + 1);
    dp[0] = 2; dp[1] = 1;
    for (int i = 2;i <= N;++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N] << '\n';
    return 0;
}