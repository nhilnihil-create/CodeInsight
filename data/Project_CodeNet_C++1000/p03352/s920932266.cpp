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

const int N = 1005;
int n, m, k, ans;
int p[N];

int main() {
    cin >> n;
    p[1] = true;
    for (int i = 2; i < n; ++i) {
        for (int j = i * i; j <= n; j *= i) {
            p[j] = true;
        }
    }
    for (int i = n; i >= 1; --i) {
        if (p[i]) {
            cout << i << endl;
            exit(0);
        }
    }
    return 0;
}
