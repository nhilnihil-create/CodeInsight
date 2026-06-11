#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <random>
#include <iomanip>
#include <bitset>
                        
using namespace std;
                        
template<typename T> void uin(T &a, T b) {
    if (b < a) {
        a = b;
    }
}

template<typename T> void uax(T &a, T b) {
    if (b > a) {
        a = b;
    }
}

#define int long long
#define ghost signed
#define left left228
#define right right228
#define prev prev228
#define list list228
#define complex complex228

int f(int n) {
	if (n == 0) return 1;
	return f(n - 1) * n;
}

ghost main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	if (a + b - 1 > n) {
		cout << -1 << '\n';
		return 0;
	}
	--a;
	vector<int> ans;
	vector< vector<int> > block(n + 1);
	int mxblock = 0;
	for (int i = 1; i <= n - b; ++i) {
		block[(i - 1) / a].push_back(i);
		mxblock = (i - 1) / a;
	}
	for (int i = mxblock; i >= 0; --i) {
		for (int x : block[i]) ans.push_back(x);
	}
	if (mxblock + 1 > b) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = n; i > n - b; --i) ans.push_back(i);
	for (int i : ans) cout << i << " ";
	cout << endl;
    return 0;
} // kek










/*3 3 2

3 3 2
3 3 2
2 3 3
2 3 3
*/






