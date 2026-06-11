#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    ll a, b;
    int k;
    cin >> a >> b >> k;
    if(a + k - 1 > b - k - 1) {
        repl(i, a, b + 1) {
            cout << i << endl;
        }
    }
    else {
        repl(i, a, a + k) {
            cout << i << endl;
        }
        repl(i, b - k + 1, b + 1) {
            cout << i << endl;
        }
    }
    return 0;
}