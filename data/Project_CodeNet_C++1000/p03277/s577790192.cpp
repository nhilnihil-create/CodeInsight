#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <queue>
#define LL long long
#define PII pair<int, int>
using namespace std;
const int MAXN = 100000;

int N, a[MAXN+5], uni[MAXN+5];
LL cnt, dp[2*MAXN+5];

bool check(int x) {
    int zero = N;
    LL res = 0, sum = 0;
    fill(dp, dp + 2 * N + 1, 0);
    for (int i = 0; i < N; i++) {
        dp[zero]++;
        if (a[i] <= x) {
            sum += dp[zero];
            zero--;
        }
        else {
            zero++;
            sum -= dp[zero];
        }
        res += sum;
    }
    return res >= cnt / 2 + 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> N;
    cnt = (LL)N * (N - 1) / 2 + N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        uni[i] = a[i];
    }

    sort(uni, uni + N);
    int M = unique(uni, uni + N) - uni, l = 0, r = M - 1, ans = -1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (check(uni[m])) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << uni[ans] << '\n';
}
