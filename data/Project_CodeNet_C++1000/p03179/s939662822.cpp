#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;
 
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define y1 abcde
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>
#define BUG cout << "acdsfas" << endl

const int mod = 1e9 + 7;
const int inf = 2e9;
const int N = 3e3 + 15;
int n, dp[N][N];
string s;

inline void add(int &a, int b) {
    a += b;
    if(a >= mod)
        a -= mod;
    if(a < 0)
        a += mod;
}

inline void calc_pref(int i) {
    for(int j = 1; j <= n; ++j)
        add(dp[i][j], dp[i][j-1]);
}

main() {
    cin >> n >> s;
    s = '#' + s;
    dp[1][1] = 1;
    for(int i = 1; i < n; ++i) {
        calc_pref(i);
        for(int j = 1; j <= i; ++j) {
            if(s[i] == '<')
                add(dp[i + 1][j + 1], dp[i][j]);
            else
                add(dp[i + 1][1], dp[i][j]),
                add(dp[i + 1][j + 1], -dp[i][j]);
        }
    }
    calc_pref(n);
    calc_pref(n);
    cout << dp[n][n] << endl;
    return 0;
}