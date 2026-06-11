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
    int N;
    ll H;
    cin >> N >> H;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    sort(b.rbegin(), b.rend());
    ll aMax = *max_element(a.begin(), a.end());
    ll ans = 0;
    // max(a[i])より大きいb[j]の刀を投げまくり
    for (int i = 0; 0 < H && i < N; i++) {
        if (aMax < b[i]) {
            H -= b[i];
            ans++;
        }
    }
    // 残ったHPはmax(a[i])を何回も振る
    if (0 < H) {
        ans += (H + aMax-1) / aMax;
    }
    cout << ans << '\n';

}
