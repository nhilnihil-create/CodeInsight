#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    if(k%2==0)
        cout << a - b;
    else
        cout << b - a;
    cout << endl;

    return 0;
}