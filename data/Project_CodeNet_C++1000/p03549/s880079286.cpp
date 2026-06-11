#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int n, m;
    cin >> n >> m;
    int t = 1900 * m + 100 * (n - m);
    // double p = pow(1.0 / 2, m);
    // double ans = 0.0;
    // rep(i, (int)1e5) {
    //     ans += (i + 1) * t * pow(1 - p, i) * p;
    // }
    // cout << (int)(ans + 0.001) << endl;
    int e = 1;
    rep(i, m) {
        e *= 2;
    }
    cout << t * e << endl;
}