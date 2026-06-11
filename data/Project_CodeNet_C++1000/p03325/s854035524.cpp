#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        while(a % 2 == 0) {
            ans++;
            a /= 2;
        }
    }
    cout << ans << endl;
    return 0;
}