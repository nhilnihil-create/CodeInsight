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

#define int ll
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
    int n, m;
    cin >> n >> m;
    vector <pi> p(n + m);
    loop(i, n) {
        cin >> p[i].F;
        p[i].S = 1;
    }
    loop(i, m)
        cin >> p[i + n].S >> p[i + n].F;
    sort(all(p), greater<pi>());
    int ans = 0, cur = n;
    for (int i = 0; cur; ++i) {
        if (p[i].S > cur) {
            ans += cur * p[i].F; 
            cur = 0;
        }
        else {
            ans += p[i].S * p[i].F;
            cur -= p[i].S;
        }
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