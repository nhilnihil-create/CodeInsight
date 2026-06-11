#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int x = 0, y = 0, z = 0;
    rep(i,n) {
        int p;
        cin >> p;
        if (p <= a) x++;
        if (a+1 <= p && p <= b) y++;
        if (b+1 <= p) z++;
    }
    cout << min({x, y, z}) << endl;
}