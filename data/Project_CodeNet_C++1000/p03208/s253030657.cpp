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
    int n, k;
    cin >> n >> k;
    vi h(n);
    rep(i, n) cin >> h[i];

    sort(ALL(h));
    int min_h = INF;
    for (int i = 0; i+k-1 < n; i++) {
        min_h = min(min_h, h[i+k-1]-h[i]);
    }
    cout << min_h << endl;
}