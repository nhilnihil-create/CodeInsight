#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int n; cin >> n;
    vector<int> value;
    vector<int> cost;
    rp(i, 0, n) {
        int v; cin >> v; value.emplace_back(v);
    }
    rp(i, 0, n) {
        int v; cin >> v; cost.emplace_back(v);
    }
    int ans = 0;
    rp(i, 0, n) {
        if(value[i] - cost[i] > 0) ans += (value[i] - cost[i]);
    }
    cout << ans << endl;
    return 0;
}