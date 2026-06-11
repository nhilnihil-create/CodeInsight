#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int x = 0, y = 0, z = 0;
    rep(i, n) {
        int p;
        cin >> p;
        if (p <= a)
            x++;
        else if (p <= b)
            y++;
        else
            z++;
    }
    cout << min({x, y, z}) << endl;
}