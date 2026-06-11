#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int a, b, c, k, m;
    cin >> a >> b >> c >> k;
    m = max(max(a, b), c);
    int tmp = m;
    rep(i, k) { m *= 2; }
    if (tmp == a)
        cout << b + c + m << endl;
    else if (tmp == b)
        cout << a + c + m << endl;
    else if (tmp == c)
        cout << a + b + m << endl;
    return 0;
}