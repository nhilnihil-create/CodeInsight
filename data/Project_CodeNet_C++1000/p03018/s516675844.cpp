#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <chrono>
#include <string>
#include <bitset>
#include <cassert>
#include <queue>
#include <memory>

//#pragma comment(linker, "/STACK:16777216")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")

using namespace std;

//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define ull unsigned long long
//#define double long double
#define int ll
//#define int ull
//#define int short
//#define int unsigned short
//#define int unsigned int
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define hash hash228
#define get get228
const int SZ = 1e2 + 4;
const double EPS = 1e-7;
const int mod = 998244353;
const int hashpow = 127;
const int inf = 2e9;

#define kek cout << "kek"

string s;

void read() {
    cin >> s;
}

void solve() {
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < (int) s.size() - 1; ++i) {
        if (s[i] == 'A') {
            ++cur;
        }
        else {
            if (s[i] == 'B' && s[i + 1] == 'C') {
                s[i] = s[i + 1] = 'A';
                s[i - cur] = 'B';
                s[i + 1 - cur] = 'C';
                ans += cur;
                ++i;
            }
            else {
                cur = 0;
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //    int t;
    //    cin >> t;
    //    for (int i = 0; i < t; ++i) {
    read();
    solve();
    //    }

    return 0;
}