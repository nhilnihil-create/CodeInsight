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
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) { cin >> a[i]; }
    ll ans = LINF;
    for (int l = 0; l + K - 1 < N; l++) {
        int r = l + K - 1;
        ll dist1 = abs(a[l]) + abs(a[r] - a[l]);
        ll dist2 = abs(a[r]) + abs(a[r] - a[l]);
        ans = min({ans, dist1, dist2});
    }
    cout << ans << '\n';
}
