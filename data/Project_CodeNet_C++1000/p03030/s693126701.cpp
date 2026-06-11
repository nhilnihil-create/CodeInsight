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
    int n; cin >> n;
    vector <tuple <string, int, int> > a(n);
    loop(i, n) {
        cin >> get<0>(a[i]) >> get<1>(a[i]);
        get<2>(a[i]) = i + 1;
    }
    sort(all(a), [](auto t1, auto t2) { return get<0>(t1) < get<0>(t2) || (get<0>(t1) == get<0>(t2) && get<1>(t1) > get<1>(t2)); });
    loop(i, n)
        cout << get<2>(a[i]) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}