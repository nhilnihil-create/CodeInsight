#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


vector<ll> divisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        if (divisors(i).size() == 8) {
            ans++;
        }
    }
    cout << ans << endl;
}
