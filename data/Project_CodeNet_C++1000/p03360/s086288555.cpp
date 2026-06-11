#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int a, b, c, k, m;
    cin >> a >> b >> c >> k;
    cout << a + b + c + max(max(a, b), c) * ((1 << k) - 1) << endl;
    return 0;
}