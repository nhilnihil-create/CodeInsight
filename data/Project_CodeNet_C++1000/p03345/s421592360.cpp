#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
 
int main()
{
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k % 2 == 0) cout << a - b << endl;
    else cout << b - a << endl;
    return 0;
}