#include <bits/stdc++.h>
#define dcout cout << fixed << setprecision(15)
#define rep(i, a) for(int i = 0; i < a; i++)
#define arep(i, x) for(auto i : x)
#define all(v) v.begin(), v.end()
#define int long long
#define F first
#define S second
#define VE vector<int>
#define pb(x) push_back(x)
using namespace std;
signed main() {
    int n;
    cin >> n;
    VE a;
    rep(i, n) {
        int enter;
        cin >> enter;
        a.pb(enter);
    }
    int ans = 0;
    rep(i, n - 1) {
        if(a[i + 1] == a[i]) {
            a[i + 1] = 10001;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}