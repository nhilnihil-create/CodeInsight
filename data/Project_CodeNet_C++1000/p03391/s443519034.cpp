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
    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    if (a == b) {
        cout << 0 << '\n';
        return 0;
    }
    ll ans = 0;
    ll mi = LINF;
    for (int i = 0; i < N; i++) {
        ans += a[i];
        if (a[i] > b[i]) {
            mi = min(mi, b[i]);
        }
    }
    cout << ans - mi << '\n';

}
