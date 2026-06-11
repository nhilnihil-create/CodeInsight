#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
// const ll MOD = 998244353;
const double PI=3.14159265358979323846;



int main() {
    int n; cin >> n;
    priority_queue<pair<ll, pair<ll, ll>> > q;
    rp(i, 0, n) {
        ll a, b; cin >> a >> b;
        q.push(make_pair(llabs(a+b), make_pair(a, b)));
    }
    ll res = 0;
    rp(i, 0, n) {
        auto x = q.top(); q.pop();
        if(i%2 == 0) res += x.second.first;
        else res -= x.second.second;
    }
    cout << res << endl;
    return 0;
}
