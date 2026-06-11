#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    ll x = pow(2, m);
    ll time = (n - m) * 100 + (m * 1900);
    cout << time * x << endl;
}
