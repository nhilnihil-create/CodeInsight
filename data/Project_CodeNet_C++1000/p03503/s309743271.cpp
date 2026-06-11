#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 105;
int F[N][10], P[N][10];
int n, ans;
int cnt[N];

int main() {
    ans = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> F[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 10; ++j) {
            cin >> P[i][j];
        }
    }
    for (int mask = 1; mask < (1 << 10); ++mask) {
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < 10; ++j) {
            if (mask & (1 << j)) {
                for (int i = 0; i < n; ++i) {
                    if (F[i][j]) {
                        ++cnt[i];
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += P[i][cnt[i]];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
