/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    int n;
    string str;
    cin >> n >> str;

    string before = str.substr(0, n);
    string after = str.substr(n, n);
    reverse(after.begin(), after.end());

    map<pair<string, string>, int> bm;
    map<pair<string, string>, int> am;

    for (int mask = 0; mask < (1 << n); mask++) {
        string before_first;
        string before_second;
        string after_first;
        string after_second;
        for (int j = 0; j < n; j++) {
            if (mask & (1LL << j)) {
                before_first += before[j];
                after_first += after[j];
            } else {
                before_second += before[j];
                after_second += after[j];
            }
        }

        bm[make_pair(before_first, before_second)]++;
        am[make_pair(after_first, after_second)]++;
    }

    int ret = 0;

    for (auto it = bm.begin(); it != bm.end(); it++) {
        auto it2 = am.find(it->first);
        if (it2 != am.end()) {
            ret += it->second * it2->second;
        }
    }

    cout << ret << endl;

    return 0;
}