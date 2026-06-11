#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll N, T, A;
    cin >> N >> T >> A;

    vector<pair<double, ll>> H(N);
    rep(i, N) {
        double tmp;
        cin >> tmp;
        H[i] = make_pair(tmp, i);
    }

    rep(i, N) { H[i].first = abs(A - (T - H[i].first * 0.006)); }
    sort(H.begin(), H.end());
    cout << H[0].second + 1 << endl;

    // rep(i, N) { cout << H[i].second << ": " << H[i].first << endl; }

    return 0;
}