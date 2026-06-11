#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define rREP(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define rFOR(i, a, b) for (int i = a; i >= b; --i)
#define aFOR(i, V) for (auto i : V)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
#define INF 1'000'000'007 // 10^9 + 7
#define MOD 1'000'000'007 // 10^9 + 7
#define lINF 1'000'000'000'000'000'007 // 10^18 + 7
// ------------------------------

int main() {
    int n;
    cin >> n;
    vector<int> odd_v(n/2);
    vector<int> even_v(n/2);
    map<int, int> odd_m;
    map<int, int> even_m;
    REP(i, n/2) {
        cin >> odd_v[i];
        cin >> even_v[i];
        odd_m[odd_v[i]] += 1;
        even_m[even_v[i]] += 1;
    }
    vector<pair<int, int>> odd_v2, even_v2;
    aFOR(i, odd_m) {
        odd_v2.push_back(make_pair(i.second, i.first));
    }
    aFOR(i, even_m) {
        even_v2.push_back(make_pair(i.second, i.first));
    }
    sort(rALL(odd_v2));
    sort(rALL(even_v2));
    int ans;
    if (odd_v2[0].second != even_v2[0].second) ans = (n/2 - odd_v2[0].first) + (n/2 - even_v2[0].first);
    else ans = min((n/2 - odd_v2[1].first) + (n/2 - even_v2[0].first),
        (n/2 - odd_v2[0].first) + (n/2 - even_v2[1].first));
    cout << ans << endl;
    return 0;
}