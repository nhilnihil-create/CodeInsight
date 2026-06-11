#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, mx, sum = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    mx = a[0];
    for (int i = 1; i < n; ++i) {
        sum += a[i];
    }
    if (mx < sum)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}