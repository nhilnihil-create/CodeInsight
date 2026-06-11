#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, h, w, ans = 0; cin >> n >> h >> w;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a >= h && b >= w) ans++;
    }
    cout << ans << endl;
    return 0;
}