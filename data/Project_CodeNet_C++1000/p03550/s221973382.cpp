#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Z, W; cin >> N >> Z >> W;
    vector<int> a(N); for (auto &x : a) cin >> x;
    if (N == 1) cout << abs(W - a[0]) << endl;
    else cout << max(abs(W - a[N-1]), abs(a[N-2] - a[N-1])) << endl;
}
