#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define emb emplace_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> inline T range(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}

inline void setin(string s) {
    freopen(s.c_str(), "r", stdin);
}

inline void setout(string s) {
    freopen(s.c_str(), "w", stdout);
}

template <typename T> void Min(T &a, T b) {
    a = min(a, b);
}

template <typename T> void Max(T &a, T b) {
    a = max(a, b);
}

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 2e3 + 15;
const int M = 4e6 + 5;
int n, a[N];
bitset <M> dp;

main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // setin("input.txt");
    cin >> n;
    dp[0] = 1;
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        dp |= dp << a[i];
    }
    for(int i = (sum + 1)/2; i < M; ++i) {
        if(dp[i])
            return cout << i << endl, 0;
    }
    return 0;
}