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

const int N = 18;

int mx[(1 << N) + 7], mx2[(1 << N) + 7];
int a[(1 << N) + 7];

void relax(int &mx, int &mx2, int x) {
	if (x > mx) {
		mx2 = mx;
		mx = x;
	} else if (x > mx2) mx2 = x;
}

ghost main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); ++i) cin >> a[i];
	mx[0] = a[0];
	int kek = 0;
	for (int i = 0; i < (1 << n); ++i) mx[i] = a[i];
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < (1 << n); ++mask) {
			if ((mask >> i) & 1) {
				relax(mx[mask], mx2[mask], mx[mask - (1 << i)]);
				relax(mx[mask], mx2[mask], mx2[mask - (1 << i)]);
			}
		}
	}
	for (int i = 1; i < (1 << n); ++i) {
		uax(kek, mx[i] + mx2[i]);
		cout << kek << '\n';
	}
	return 0;
} // kek ;



