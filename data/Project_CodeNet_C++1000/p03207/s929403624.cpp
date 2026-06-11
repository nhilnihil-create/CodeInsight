#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int n;
    cin >> n;

    int p[n];
    rep(0, n) cin >> p[i];

    sort(p, p+n);

    int sum = 0;
    rep(0, n-1) sum += p[i];
    sum += p[n-1] / 2;

    cout << sum << endl;
}

int main() {
    solve();

    return 0;
}
