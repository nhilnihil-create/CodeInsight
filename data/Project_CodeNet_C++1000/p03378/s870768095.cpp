#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, m, x, left = 0, right = 0, tmp;
    cin >> n >> m >> x;
    rep(i, m) {
        cin >> tmp;
        if (tmp < x)
            left++;
        else
            right++;
    }

    cout << min(left, right) << endl;
    return 0;
}