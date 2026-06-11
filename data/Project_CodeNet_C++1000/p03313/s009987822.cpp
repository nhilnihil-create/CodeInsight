#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

void upd(int a[], pii &x, int y) {
    if (a[y] > a[x.first]) {
        x.second = x.first;
        x.first = y;
    } else if (x.second == -1 || y != x.first && a[y] > a[x.second]) {
        x.second = y;
    }
}

void upd(int a[], pii &x, pii y) {
    upd(a, x, y.first);
    if (y.second != -1) {
        upd(a, x, y.second);
    }
}

int main() {
    int n;
    cin >> n;
    int a[1<<n];
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }

    pii m[1<<n];
    for (int i = 0; i < (1 << n); i++) {
        m[i] = pii(i, -1);
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                upd(a, m[i], m[i&~(1<<j)]);
            }
        }
    }

    int ans = -1;
    for (int i = 1; i < (1 << n); i++) {
        ans = max(ans, a[m[i].first] + a[m[i].second]);
        cout << ans << endl;
    }

    return 0;
}
