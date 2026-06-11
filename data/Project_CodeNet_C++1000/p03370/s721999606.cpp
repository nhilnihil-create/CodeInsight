#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, X, m, mmin = 1000, msum = 0;
    cin >> N >> X;
    rep(i, N) {
        cin >> m;
        mmin = min(mmin, m);
        msum += m;
    }
    cout << N + (X - msum) / mmin << "\n";
}