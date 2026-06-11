#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, X;
    cin >> n >> X;
    vector<ll> x(n), sa(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sa[i] = abs(X - x[i]);
    }
    
    int r = accumulate(sa.begin(), sa.end(), 0, [](int m, int n) {
        return gcd(m, n);
    });

    cout << r << endl;
    return 0;
}