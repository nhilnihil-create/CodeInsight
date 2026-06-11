#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int a, b, c, x;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;
    int ans = 0;
    rep(i, a + 1) {
        rep(j, b + 1) {
            rep(k, c + 1) {
                if(x == 500 * i + 100 * j + 50 * k) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}