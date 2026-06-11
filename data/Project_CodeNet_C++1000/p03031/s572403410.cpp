#define _CRT_SECURE_NO_WARNINGS

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
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

//#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define mkt make_tuple
#define no {cout << -1; return;}

void solve() {
    int n, m, on = 0;
    cin >> n >> m;
    vector <int> bulb(m);
    loop(i, m) {
        int k; cin >> k;
        loop(j, k) {
            int bit; cin >> bit;
            bulb[i] ^= (1 << (bit - 1));
        }
    }
    loop(i, m) {
        int bit; cin >> bit;
        if (bit)
            on ^= (1 << i);
    }
    int ans = 0;
    loop(mask, (1 << n)) {
        int curon = 0;
        loop(bit, n)
            if (mask & (1 << bit))
                loop(i, m)
                    if (bulb[i] & (1 << bit))
                        curon ^= (1 << i);
        ans += (on == curon);
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}