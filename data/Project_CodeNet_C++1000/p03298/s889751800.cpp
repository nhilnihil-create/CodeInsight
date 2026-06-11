#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
#include <omp.h>
using namespace std;
#define eps 0.000001
#define LONG_INF 10000000000000
#define GOLD 1.61803398874989484820458
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
int main() {
#define int long long
	int n;
	string s;
	cin >> n >> s;
	string a, b;
	REP(i, 2 * n) {
		if (i < n) {
			a.push_back(s[i]);
		}
		else {
			b.push_back(s[i]);
		}
	}
	reverse(b.begin(), b.end());
	int ans[2] = {};
	map<pair<string,string>, int> gogo;
	for (int tere = 0; tere < 1; ++tere) {
		for (int i = 0; i < (1 << n); ++i) {
			string c, d;
			int now_itr = i;
			for (int q = 0;q < n; ++q) {
				if (now_itr % 2 == 1) {
					c.push_back(a[q]);
				}
				else {
					d.push_back(a[q]);
				}

				now_itr /= 2;
			}
			gogo[make_pair(c,d)]++;
		}
		for (int i = 0; i < (1 << n); ++i) {
			string c, d;
			int now_itr = i;
			for (int q = 0;q < n; ++q) {
				if (now_itr % 2 == 1) {
					c.push_back(b[q]);
				}
				else {
					d.push_back(b[q]);
				}
				now_itr /= 2;
			}
			ans[0] += gogo[make_pair(c,d)];
		}
	}
	cout << ans[0] << endl;
}