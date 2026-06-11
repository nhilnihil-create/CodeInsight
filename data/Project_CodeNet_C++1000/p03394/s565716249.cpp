// Why am I so dumb? :c
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int INF = (int)1e9;

int dp[6][30005];

bool p[6][30005];

vector<int> ans;

int n;

void solve() {
    scanf("%d", &n);

    if (n == 3) {
        printf("2 5 63\n");
        return;
    }

    if (n == 4) {
        printf("2 5 20 63\n");
        return;
    }

    for (int i = 2; i <= 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            dp[j][i] = -INF;
        }
    }

    dp[5][3] = 2;
    dp[2][2] = 1;

    p[5][3] = 1;
    p[2][2] = 1;

    for (int i = 4; i <= 30000; ++i) {
        for (int cur = 0; cur < 6; ++cur) {
            dp[cur][i] = dp[cur][i - 1];
            p[cur][i] = 0;
        }

        if (i % 2 && i % 3) {
            continue;
        }

        for (int cur = 0; cur < 6; ++cur) {
            int val = dp[cur][i - 1] + 1;
            int nxt = (cur + i) % 6;

            if (val <= n && val > dp[nxt][i]) {
                dp[nxt][i] = val;
                p[nxt][i] = 1;
            }
        }
    }

    for (int i = 30000, s = 0; i > 1; --i) {
        if (p[s][i]) {
            s = (s - (i % 6) + 6) % 6;
            printf("%d ", i);
        }
    }
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}