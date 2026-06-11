#pragma GCC optimize("Ofast")
/*#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")*/
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

const int N = 100 * 1000 + 228;

int n, ptr = 1;
bool is[N];
vector< pair<int, int> > e;

int build(int pos) {
	int sz = pos;
	int root = ptr++;
	--pos;
	while (pos && !is[pos]) --pos;
	if (pos) {
		e.push_back(make_pair(root, build(pos)));
		sz -= (pos + 1);
		for (int i = 0; i < sz; ++i) e.push_back(make_pair(root, ptr++));
	}
	return root;
}


ghost main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	n = (int)s.size();
	for (int i = 1; i <= n; ++i) {
		char c = s[i - 1];
		if (c == '0') is[i] = 0;
		else is[i] = 1;
	}
	if (is[n]) {
		cout << -1 << '\n';
		return 0;
	}
	if (!is[1]) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		if (is[i] != is[n - i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	build(n);
	for (auto p : e) cout << p.first << " " << p.second << endl;
	return 0;
} // kek ;



