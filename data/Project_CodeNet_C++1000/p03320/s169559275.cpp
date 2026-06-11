#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int K;

double Snuke(ll x) {
    ll tmp = 0, c = x;
    while(c) {
        tmp += c % 10;
        c /= 10;
    }
    return 1.0 * x / tmp;
}

void run() {
    ll res = 0, x = 1;
    while(K--) {
        double t1, t2;
        while(true) {
            t1 = Snuke(res + x), t2 = Snuke(res + x * 10);
            if(t1 <= t2) break;
            x *= 10;
        }
        res += x;
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    while(cin >> K) run();
    return 0;
}
