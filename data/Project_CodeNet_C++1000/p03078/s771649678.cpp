#include <bits/stdc++.h>
using namespace std;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;
 
int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> A, AB, C, ABC;
    rp(i, 0, x) {
        ll a; cin >> a;
        A.emplace_back(a);
    }
    rp(i, 0, y) {
        ll b; cin >> b;
        rp(j, 0, x) {
            AB.emplace_back(A.at(j) + b);
        }
    }
    rp(i, 0, z) {
        ll c; cin >> c;
        C.emplace_back(c);
    }
    sort(AB.rbegin(), AB.rend());
    rp(i, 0, min(x*y, k)) {
        rp(j, 0, z) {
            ABC.emplace_back(AB.at(i) + C.at(j));
        }
    }
    sort(ABC.rbegin(), ABC.rend());
    rp(i, 0, k) cout << ABC.at(i) << endl;
    return 0;
}
