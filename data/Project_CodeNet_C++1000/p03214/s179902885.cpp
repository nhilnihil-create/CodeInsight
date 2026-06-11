#include <algorithm>
#include <bitset>
#include <cassert>
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
ll const MAX_N = 100000;
ll const MOD = 1000000007;

int main() {
    ll N;
    cin >> N;
    vector<double> a(N);

    rep(i, N) cin >> a[i];
    double avg = 0;
    rep(i, N) { avg += a[i]; }
    avg /= (double)N;

    vector<pair<double, ll>> diff;
    rep(i, N) {
        pair<double, ll> p = make_pair(abs(avg - a[i]), i);
        diff.push_back(p);
    }

    // cout << avg << endl;
    sort(diff.begin(), diff.end());
    // repv(diff) { cout << (*it).first << "," << (*it).second << endl; }
    cout << diff[0].second << endl;

    return 0;
}
