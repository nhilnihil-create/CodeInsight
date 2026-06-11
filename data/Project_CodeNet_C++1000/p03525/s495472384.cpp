#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int dfs(map<int, int>::iterator it, vector<int> &times, map<int, int> &d) {
    if (it == d.end()) {
        int mindiff = 25;
        int nt = times.size();
        for (int i = 0; i < nt; ++i) {
            for (int j = 0; j < nt; ++j) {
                if (i == j)
                    continue;
                chmin(mindiff, abs(times[i] - times[j]));
                chmin(mindiff, 24 - abs(times[i] - times[j]));
            }
        }
        return mindiff;
    }
    int ret = 0;
    if (it->second == 1) {
        auto ntimes = times;
        ntimes.push_back(it->first);
        chmax(ret, dfs(next(it), ntimes, d));
        ntimes = times;
        ntimes.push_back(24 - it->first);
        chmax(ret, dfs(next(it), ntimes, d));
    }
    if (it->second == 2) {
        auto ntimes = times;
        ntimes.push_back(it->first);
        ntimes.push_back(24 - it->first);
        chmax(ret, dfs(next(it), ntimes, d));
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    map<int, int> d;
    bool zero = false;
    for (int i = 0; i < n; ++i) {
        int dd;
        cin >> dd;
        d[dd]++;
        if (d[dd] == 3)
            zero = true;
    }
    if (zero) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> times = {0};
    cout << dfs(d.begin(), times, d) << "\n";

    return 0;
}
