#include <bits/stdc++.h>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastio;
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    cout << ((a == b) ? "YES" : "NO") << endl;
}