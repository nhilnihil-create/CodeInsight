#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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

struct city {
    ll idx, p, y;

    bool operator<(const city& another) const { return y < another.y; }
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<city> cities(M);

    rep(i, M) {
        ll p, y;
        cin >> p >> y;

        city c = {i, p, y};
        cities[i] = c;
    }

    sort(cities.begin(), cities.end());

    vector<ll> cnt(N, 0);
    vector<string> ids(M);
    stringstream ss;

    repv(cities) {
        cnt[(*it).p - 1]++;
        ss << setw(6) << setfill('0') << (*it).p;
        ss << setw(6) << setfill('0') << cnt[(*it).p - 1];
        string str = ss.str();
        ids[(*it).idx] = str;
        // cout << (*it).idx << ": " << ss.str() << endl;
        ss.str("");
        ss.clear(stringstream::goodbit);

        //  ids[(*it).idx] =
        //     cout << (*it).idx << "," << (*it).p << "," << (*it).y << endl;
    }

    repv(ids) { cout << *it << endl; }

    return 0;
}
