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
    ll N;
    cin >> N;
    for (ll a = 1; a <= 3500; a++) {
        for (ll b = 1; b <= 3500; b++) {
            ll n = N * a * b;
            ll d = 4 * a * b - N * (a + b);
            if (d == 0) continue;
            if ((n % d) == 0) {
                ll c = n / d;
                if (1 <= c && c <= 3500) {
                    cout << a << ' ' << b << ' ' << c << '\n';
                    return 0;
                }
            }
        }
    }
}
