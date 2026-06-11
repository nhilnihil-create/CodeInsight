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
    int m, k;
    cin >> m >> k;
    if (m == 1) {
        if (k == 0)
            cout << "1 1 0 0";
        else
            cout << -1;
        return;
    }
    if (k > (1 << m) - 1)
        no;
    loop(i, (1 << m))
        if (i != k)
            cout << i << " ";
    cout << k << " ";
    for (int i = (1 << m) - 1; i >= 0; --i)
        if (i != k)
            cout << i << " ";
    cout << k;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("output.txt", "w", stdout);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}