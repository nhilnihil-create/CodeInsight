#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int n, m;
    cin >> n >> m;
    int x = 1900 * m + (n-m) * 100;
    cout << x * (1 << m) << endl;
}

int main() {
    solve();
    return 0;
}
