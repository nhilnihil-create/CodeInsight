#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    rep(i, n - 1) {
        if(a[i] == a[i + 1]) {
            ans++;
            a[i + 1] = 105 + i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}