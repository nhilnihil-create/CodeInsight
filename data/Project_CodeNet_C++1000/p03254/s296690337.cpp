#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    sort(a.begin(), a.end());

    int end = 0;
    rep(i, N) {
        if (a[i] <= x) {
            x -= a[i];
        } else {
            break;
        }
        ++end;
    }

    if (end == N && x > 0)
        --end;
    cout << end << endl;

    return 0;
}