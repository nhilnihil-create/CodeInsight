#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    char c;
    int ans = 0;
    rep(i, 4) {
        cin >> c;
        if (c == '+')
            ans++;
        else if (c == '-')
            ans--;
    }
    cout << ans << endl;
    return 0;
}