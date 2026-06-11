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

int a, b, k;
int main() {
    cin >> a >> b >> k;
    if (b - a + 1 <= 2 * k) {
        for (int i = a; i <= b; ++i) {
            cout << i << endl;
        }
    } else {
        for (int i = 0; i < k; ++i) {
            cout << a + i << endl;
        }
        for (int i = k - 1; i >= 0; --i) {
            cout << b - i << endl;
        }
    }
    return 0;
}
