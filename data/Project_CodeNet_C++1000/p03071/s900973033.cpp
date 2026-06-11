#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int a, b, ans;
    cin >> a >> b;
    if (a > b) {
        ans = a + (a - 1);
    } else if (a == b) {
        ans = a + b;
    } else if (a < b) {
        ans = b + (b - 1);
    }
    cout << ans << endl;
    return 0;
}