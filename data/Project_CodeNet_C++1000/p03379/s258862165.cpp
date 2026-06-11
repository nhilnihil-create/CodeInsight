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

const int N = 2e5 + 5;
int n;
int a[N], b[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    int l = a[n / 2 - 1];
    int r = a[n / 2];
    for (int i = 0; i < n; ++i) {
        if (b[i] <= l)
            cout << r << endl;
        else
            cout << l << endl;
    }
    return 0;
}
