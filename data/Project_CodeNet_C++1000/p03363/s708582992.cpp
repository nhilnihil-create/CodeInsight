#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    REP(i, 0, N) cin >> A[i];

    unordered_map<ll, ll> m;
    ll prev = 0;
    m[prev]++;
    REP(i, 0, N) {
        prev += A[i];
        m[prev]++;
    }

    ll ans = 0;
    for (auto elm : m) ans += elm.second * (elm.second - 1) / 2;
    cout << ans << endl;

    return 0;
}