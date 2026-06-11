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
string s;
vector<pair<char, int>> moving;
int solve(int now) {
	for (int i = 0; i < moving.size(); ++i) {
		if (s[now] == moving[i].first) {
			now += moving[i].second;
			if (now < 0) return -1;
			if (now >= s.length()) return 1;
		}
	}
	return 0;
}
int main(){
	int n, query;
	cin >> n >> query;
	cin >> s;
	REP(i, query) {
		string a, b;
		cin >> a >> b;
		moving.push_back(make_pair(a[0], b == "R" ? 1 : -1));
	}
	int bot = 0;
	int top = n-1;
	long long ans = n;
	while (top - bot > 1) {
		int mid = (top + bot) / 2;
		if (solve(mid) == -1) {
			bot = mid;
		}
		else {
			top = mid;
		}
	}
	if (solve(top) == -1) {
		ans -= top + 1;
	}
	else if (solve(bot) == -1) {
		ans -= bot + 1;
	}
	bot = 0;
	top = n - 1;
	while (top - bot > 1) {
		int mid = (top + bot) / 2;
		if (solve(mid) == 1) {
			top = mid;
		}
		else {
			bot = mid;
		}
	}
	if (solve(bot) == 1) {
		ans -= n - bot;
	}
	else if (solve(top) == 1) {
		ans -= n - top;
	}
	cout << ans << endl;
	return 0;
}
