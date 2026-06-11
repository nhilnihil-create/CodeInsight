#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
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
    ll N, M;
    cin >> N >> M;
    vector<pll> v(N);
    ll a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v[i] = pll(a, b);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll cnt = min(M, v[i].second);
        M = max(M - cnt, 0LL);
        ans += cnt * v[i].first;
    }
    cout << ans << '\n';
}
