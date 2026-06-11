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

const int N = 11;
int n, m, p, c;
ii a[N];
int gain[N];

int main() {
    cin >> n >> m;
    m /= 100;
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> p >> c;
        a[i] = {p, c};
        gain[i] = p * (i + 1) + c / 100;
    }
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        int cnt = 0;
        int mi = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += gain[j];
                cnt += a[j].first;
            } else {
                mi = j;
            }
        }
        if (sum < m) {
            int d = m - sum;
            if (a[mi].first * (mi + 1) < d)
                continue;
            cnt += (d + mi) / (mi + 1);
        }

        ans = min(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}
