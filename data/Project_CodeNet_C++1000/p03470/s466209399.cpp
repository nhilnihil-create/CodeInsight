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
int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int *p = unique(a, a + n);
    cout << (p - a) << endl;
    return 0;
}
