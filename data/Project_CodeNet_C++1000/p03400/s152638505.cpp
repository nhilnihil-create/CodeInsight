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
    int d, x;
    cin >> d >> x;
    int ans = x;
    rep(i, n) {
        int a;
        cin >> a;
        int k = 1;
        while(k <= d) {
            ans++;
            k += a;
        }
    }
    cout << ans << endl;
    return 0;
}