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

const int N = 1e5 + 5;
int n, l, r, cnt;
bool a[N];
int sum[N];
void init() {
    fill(a, a + N, true);
    a[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (a[i]) {
            for (int j = i + i; j <= N; j += i) {
                a[j] = false;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        if ((i + 1) % 2 == 0 && a[i] && a[(i + 1) / 2]) {
            ++cnt;
        }
        sum[i] = cnt;
    }
}

int main() {
    init();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}
