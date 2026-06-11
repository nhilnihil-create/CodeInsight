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
    string S;
    cin >> S;

    vector<ll> idx;
    rep(i, S.length()) {
        if (S[i] == 'W') {
            idx.push_back(i);
        }
    }

    // repv(idx) cout << *it << " ";

    ll sum = 0;
    repv(idx) sum += (*it);

    ll N = idx.size();
    ll ans = sum - N * (N - 1) / 2;
    cout << ans << endl;

    return 0;
}
