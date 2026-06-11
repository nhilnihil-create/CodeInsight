#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

char S[8001];
int n, x, y;
vector<int> mv[2];

bool dp[16001], tp[16001];
bool check(vector<int> &vs, int x) {
    if (x > n || x < -n) return 0;
    for (int i = 0; i <= n + n; ++i) tp[i] = dp[i] = 0;
    dp[n] = 1;
    for (int v : vs) {
        for (int i = 0; i <= n + n; ++i) {
            if (dp[i]) {
                tp[i + v] = 1;
                tp[i - v] = 1;
            }
        }
        for (int i = 0; i <= n + n; ++i) {
            dp[i] = tp[i];
            tp[i] = 0;
        }
    }
    return dp[x + n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S >> x >> y;
    n = strlen(S);
    int st = 0;
    for (int i = 0; i < n; ++i) {
        if (S[i] == 'T') st ^= 1;
        else {
            int j = i;
            while (j + 1 < n && S[j + 1] == 'F') ++j;
            if (i > 0) mv[st].push_back(j - i + 1);
            else x -= j - i + 1;
            i = j;
        }
    }
    printf(check(mv[0], x) && check(mv[1], y) ? "Yes\n" : "No\n");
    return 0;
}