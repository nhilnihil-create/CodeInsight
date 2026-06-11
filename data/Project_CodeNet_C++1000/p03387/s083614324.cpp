#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;
 
int main() {
    int ans;
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int m = a[0];
    int abc = a[0] + a[1] + a[2];
    if ((3 * m - abc) % 2 == 0)
        ans = (3 * m - abc) / 2;
    else
        ans = (3 * (m + 1) - abc) / 2;
    cout << ans << endl;
    return 0;
}