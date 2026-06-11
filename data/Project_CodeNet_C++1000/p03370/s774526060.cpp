#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, x, mi;
    cin >> n >> x;
    vector<int> m(n);
    rep(i, n) {
        cin >> m[i];
        x -= m[i];
    }
    sort(m.begin(), m.end());
    mi = m[0];
    cout << m.size() + x / mi << endl;
    return 0;
}