#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <string.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n;
ll dp[19][19];
string s;
ll ans;

int main() {
    cin >> n >> s;
    rep(i,(1<<n)) {
        string s1, s2;
        rep(j,n) {
            if (i&(1<<j)) s1.push_back(s[j]);
            else s2.push_back(s[j]);
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int j = 0; j <= n-s1.size(); j++) {
            for (int k = 0; k <= n-s2.size(); k++) {
                if (j < s2.size() && s2[j] == s[n+j+k]) dp[j+1][k] += dp[j][k];
                if (k < s1.size() && s1[k] == s[n+j+k]) dp[j][k+1] += dp[j][k];
            }
        }
        ans += dp[s2.size()][s1.size()];
    }
    cout << ans << endl;
}