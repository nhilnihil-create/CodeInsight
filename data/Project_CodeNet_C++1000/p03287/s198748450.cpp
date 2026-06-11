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
/* function */
/* main */
int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    vector<ll> sum(N+1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum[i+1] = (sum[i] + a[i]) % M;
    }
    // Bi = A0 + ... + Ai とする
    // (A_l + ... + A_r) = Br - B{l-1} mod M == 0;
    // <=> Br = B{l-1} (mod M)
    // 数えるべきは、Bi = Bj mod M となる 0 ≤ i < j ≤ N の組の個数です
    map<ll, ll> mp;
    for (int i = 0; i < N+1; i++) mp[sum[i]]++;
    ll ans = 0;
    for (auto m : mp) ans += m.second * (m.second - 1) / 2;
    cout << ans << '\n';
}
