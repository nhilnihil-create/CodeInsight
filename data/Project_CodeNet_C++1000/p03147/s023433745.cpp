#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i; i < n; i++) cin >> h[i];

    int ans = 0;
    int active = 0;
    for (int i = 0; i < n; i++)
    {
        //区間は足りていますか
        if (active >= h[i]) {
            active = h[i];
        } else {
            ans += h[i] - active;
            active = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}