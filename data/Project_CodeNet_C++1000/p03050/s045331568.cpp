#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<ll> factorization(ll a) {
    vector<ll> ret;
    for (ll i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            ret.push_back(i);
            if (i * i != a) ret.push_back(a / i);
        }
    }
    return ret;
}
/* function */
/* main */
int main(){
    ll a;
    cin >> a;
    vector<ll> f = factorization(a);
    sort(f.rbegin(), f.rend());
    ll ans = 0;
    int l = f.size();
    for (int i = 0; i < l/2; i++) {
        int j = l - 1 - i;
        if (f[i] - 1 != f[j]) ans += f[i] - 1;
    }
    cout << ans << '\n';
}
