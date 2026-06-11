#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <random>
#include <complex>
#include <random>
 
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> cnt;
    vector<int> a(n);
    for (auto &t : a) {
        cin >> t;
        cnt[t]++;
    }  
    int ans = 0;
    for (int i = 30; i > 0; i--) {
        for (auto f : a) {
            int pr = (1 << i) - f;
            if (pr > 0 && pr < (1 << i)) {
                if (f == pr) {
                    if (cnt[f] > 1) {
                        cnt[f] -= 2;
                        ans++;
                    }
                } else {
                    if (cnt[f] > 0 && cnt[pr] > 0) {
                        cnt[f]--;
                        cnt[pr]--;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
