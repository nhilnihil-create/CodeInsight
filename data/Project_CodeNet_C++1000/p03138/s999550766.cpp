#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <fstream>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
#include <random>
using namespace std;
using ll = long long;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> z(n);
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    ll ans = 0;
    for (int i = 60; i > -1; --i) {
        ll o = 0;
        ll l = 0;
        for (int j = 0; j < n; j++) {
            if (z[j] & (1ll << i)) {
                l++;
            }
            else o++;
        }
        if (l >= o) {
            ans += l * (1ll << i);
            if (k & (1ll << i)) {
                for (int j = 0; j < 60; j++) {
                    k |= (1ll << j);
                }
            }
        }
        else {
            if(k&(1ll<<i))ans += o * (1ll << i);
            else ans += l * (1ll << i);
        }
    }
    cout << ans << endl;
}