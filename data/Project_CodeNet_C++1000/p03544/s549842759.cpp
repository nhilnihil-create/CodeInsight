#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

ll a[90];

ll dfs(ll n) {
    if (a[n] != 0)
        return a[n];
    else
        a[n] = dfs(n - 1) + dfs(n - 2);

    return a[n];
}

int main() {
    ll n;
    cin >> n;

    a[0] = 2;
    a[1] = 1;
    cout << dfs(n) << endl;
    return 0;
}
