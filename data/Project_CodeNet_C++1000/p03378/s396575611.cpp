#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define REP(i, n) for (long long i = 0; i < (n); i++)
const ll INF = 1LL << 60;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
};
signed main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> as(m);
    int bigger = 0;
    int smaller = 0;
    REP(i, m) {
        cin >> as[i];
        if (as[i] < x) {
            smaller++;
        }
        if (as[i] > x) {
            bigger++;
        }
    }
    cout << min(bigger, smaller) << endl;
}