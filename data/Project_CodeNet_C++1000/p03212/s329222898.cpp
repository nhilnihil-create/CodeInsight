#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll check (ll a) {
    vector<bool> check(3,false);
    while (a) {
        ll num = a % 10;
        if (num == 3) check[0] = true;
        else if (num == 5) check[1] = true;
        else if (num == 7) check[2] = true;
        else return 0;
        a /= 10;
    }
    return (check[0] && check[1] && check[2] ? 1ll : 0ll);
}

ll dfs(ll a, ll n) {
    if (a > n) return 0;
    ll res = check(a);
    res += dfs(a * 10 + 3, n);
    res += dfs(a * 10 + 5, n);
    res += dfs(a * 10 + 7, n);
    return res;
}

int main() {
    ll n; cin >> n;
    cout << dfs(0ll, n) << endl;
    return 0;
}