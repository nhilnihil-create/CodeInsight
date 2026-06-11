#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
//i64 mod = 998244353;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;



int main(int argc, char **argv) {
    i64 n;
    cin >>n;

    vector<i64> a(n);
    map<i64, i64> mp;
    i64 sum{0};
    mp[0]=1;
    for (i64 i=0; i<n; ++i) {
        cin >> a[i];
        sum += a[i];
        auto it = mp.find(sum);
        if (it == mp.end()) {
            mp[sum] = 0;
        }
        ++mp[sum];
    }

    i64 ans{0};

    for (auto kv : mp) {
        if (kv.second>1) {
            //cout << kv.first << " " << kv.second << std::endl;
            ans += (kv.second * (kv.second-1)) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}
