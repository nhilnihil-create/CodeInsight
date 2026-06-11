// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;
template <typename T = vii> 
using vec = vector<T>;

const ll INF = 1e18, MOD = 1e9 + 7;

const int MAX = 1e6;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("in.in", "r", stdin);

    int n;
    cin >> n;
    vii v(n);
    for (int &e : v) {
        cin >> e;
    }   
    sort(v.begin(), v.end());
    pair<double, int> res(INF, INF); 
    for (int i = 0; i < n; i++) {
        res = min(res, {abs(double(v.back()) / 2 - v[i]), i});
    }
    cout << v.back() << ' ' << v[res.second] << '\n';
}