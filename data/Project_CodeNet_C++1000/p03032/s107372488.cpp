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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    loop(i, n)
        cin >> a[i];
    int ans = 0;
    for (int del = 0; del <= k; ++del) {
        int R = min(k - del, n);
        for (int i = 0; i <= R; ++i) {
            int sum = 0;
            vector <int> ret;
            for (int j = 0; j < i; ++j) {
                sum += a[j];
                ret.pb(a[j]);
            }
            for (int j = n - 1; j >= n - (R - i); --j) {
                sum += a[j];
                ret.pb(a[j]);
            }
            sort(all(ret));
            for (int j = 0; j < del && j < ret.size() && ret[j] < 0; ++j)
                sum -= ret[j];
            ans = max(ans, sum);
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