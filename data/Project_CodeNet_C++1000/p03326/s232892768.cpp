#include <fstream>
#include <numeric>
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
 
using namespace std;
 
#define ll long long
const int N = (ll)(2e5) + 100;
 
int ptr = 0;

void solve() {
    ll n,m;cin >> n >> m;
    ll maxi = 0;
    ll a[n + 1][3];
    for (int i = 1;i <= n;i ++) {
        for (int j = 0;j < 3;j ++) {
            cin >> a[i][j];
        }
    }
    ll res = 0;
    for (int k = 0;k < 8;k ++) {
        vector<ll> _sum;
        for (int i = 1;i <= n;i ++) {
            ll cur = 0;
            for (int j = 0;j < 3;j ++) {
                if (k & (1 << j)) cur += a[i][j];
                else cur -= a[i][j];
            }
            _sum.push_back(cur);
        }
        ll now = 0;
        sort(_sum.begin(), _sum.end());
        reverse(_sum.begin(), _sum.end());
        for (int i = 0;i < m;i ++) {
            now += _sum[i];
        }
        res = max(res, now);
    }
    cout << res << "\n";
}

void test() {
}

int main() {
    freopen("debug.txt", "w", stderr);
    solve();
    return 0;
}