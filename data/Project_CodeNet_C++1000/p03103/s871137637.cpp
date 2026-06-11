#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<ll, ll> pll;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    ll n, m;
    cin >> n >> m;
    vector<pll> v(n);
    ll a, b;
    for (int i = 0; i < n; i++) {cin >> a >> b; v[i] = pll(a, b);}
    sort(v.begin(), v.end());
    ll total = 0;
    for (int i = 0; i < n; i++) {
        int cnt = min(m, v[i].second);
        m = max(0LL, m - v[i].second);
        total += cnt * v[i].first;
    }
    cout << total << '\n';
}
