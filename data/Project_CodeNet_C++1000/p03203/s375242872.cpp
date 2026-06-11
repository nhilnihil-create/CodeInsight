#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MaxN = 200000 + 5;
const int MaxH = 200000 + 5, MaxW = 200000 + 5;

int N, H, W;
int X[MaxN], Y[MaxN];
int dp[MaxN];
vector <int> vec[MaxW];

void init() {
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d %d", &X[i], &Y[i]);
}

void solve() {
    for (int i = 1; i <= N; ++i)
        vec[Y[i]].push_back(X[i]);
    for (int i = 1; i <= W; ++i) sort(vec[i].begin(), vec[i].end());

    dp[1] = 1;
    for (int i = 1; i < W; ++i) {
        int j = i + 1;
        auto beg = lower_bound(vec[j].begin(), vec[j].end(), dp[i] + 1);
        if (beg == vec[j].end()) dp[j] = dp[i] + 1;
        else {
            int worst = dp[i] + 1;
            for (; beg != vec[j].end(); ++beg) {
                if (*beg == worst) worst++;
                else break;
            }
            dp[j] = worst;
        }
    }

    int ans = H;
    for (int i = 1; i <= N; ++i) {
        int x = X[i], y = Y[i];
        if (x > dp[y]) ans = min(ans, x - 1);
    }
    cout << ans << endl;
}

int main() {
    init();
    solve();
    return 0;
}