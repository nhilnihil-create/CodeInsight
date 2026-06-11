#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    sort(a.rbegin(), a.rend());
    cout << (a[0] * 10 + a[1]) + a[2] << endl;

    return 0;
}