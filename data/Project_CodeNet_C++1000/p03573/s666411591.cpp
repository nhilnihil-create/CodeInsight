#include <bits/stdc++.h>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b)
        cout << c;
    else if (a == c)
        cout << b;
    else
        cout << a;
    cout << endl;
}