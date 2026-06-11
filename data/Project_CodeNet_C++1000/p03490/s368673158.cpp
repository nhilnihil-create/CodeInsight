#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define forn(i, n) for (ll i = 0; i < (ll) n; ++i)
#define sz(a) static_cast<int>(a.size())

char buff[(int) 2e7 + 17];
const ll inf = (ll) 1e9 + 7ll;

const int maxn = (int) 1e4 + 17;

int n, x, y;
string s;
vector<int> a, b;
bool dp[2][2][maxn];

bool read() {
    if (scanf("%s", buff) != 1)
        return false;

    scanf("%d %d", &x, &y);
    return true;
}

int sgn(int x) {
    return x >= 0 ? 0 : 1;
}

bool calc(vector<int> a, int x) {
    memset(dp, false, sizeof(dp));
    int nn = sz(a);
    dp[0][0][0] = true;

    for (int i = 0; i < nn; ++i) {
        for (int j = 0; j <= 8000; ++j)
            dp[i & 1 ^ 1][0][j] = dp[i & 1 ^ 1][1][j] = false;

        for (int j = 0; j <= 8000; ++j) {
            if (dp[i & 1][0][j]) {
                int y = j;
                dp[i & 1 ^ 1][sgn(y + a[i])][abs(y + a[i])] = true;
                dp[i & 1 ^ 1][sgn(y - a[i])][abs(y - a[i])] = true;
            }

            if (dp[i & 1][1][j]) {
                int y = -j;
                dp[i & 1 ^ 1][sgn(y + a[i])][abs(y + a[i])] = true;
                dp[i & 1 ^ 1][sgn(y - a[i])][abs(y - a[i])] = true;
            }
        }
    }

    return dp[nn & 1][sgn(x)][abs(x)];
}

void solve() {
    s = buff;
    n = sz(s);

    int len = 0, c = 0;

    for (int i = 0; i < n; ++i)
        if (s[i] == 'F') {
            ++len;
        } else {
            if (len == 0) {
                c ^= 1;
                continue;
            }

            if (c == 0)
                a.push_back(len);
            else
                b.push_back(len);

            c ^= 1;
            len = 0;
        }

    if (len != 0) {
        if (c == 0)
            a.push_back(len);
        else
            b.push_back(len);
    }

    if (s[0] != 'T') {
        reverse(a.begin(), a.end());
        x -= a.back();
        a.pop_back();
        reverse(a.begin(), a.end());
    }

    auto f1 = calc(a, x);
    auto f2 = calc(b, y);

    if (f1 && f2)
        printf("Yes\n");
    else
        printf("No\n");
}

int main() {
#if SEREZHKA
    freopen("file.in", "r", stdin);
#endif

    while (read())
        solve();

    return 0;
}
