#define  _CRT_SECURE_NO_WARNINGS
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
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int main() {
#define int long long
	int n;
	cin >> n;
	vector<pair<int, int>> input;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		input.push_back(make_pair(a, b));
	}
	REP(i, n) {
		if ((LONG_INF + input[i].first + input[i].second) % 2 != (LONG_INF + input[0].first + input[0].second) % 2) {
			cout << -1 << endl;
			return 0;
		}
	}
	int gogo = input[0].first + input[0].second + LONG_INF;
	gogo %= 2;
	if (gogo == 0) {
		cout << "32" << endl;
		cout << "1 ";
	}
	else {
		cout << "31" << endl;
	}
	for (long long i = 0; i < 31; ++i) {
		cout << (1LL << i) << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		if (gogo == 0) {
			cout << "L";
			input[i].first += 1LL;
		}
		int x = input[i].first + input[i].second;
		int y = input[i].first - input[i].second;
		x += (1LL << 31LL) - 1LL;
		y += (1LL << 31LL) - 1LL;
		x /= 2LL;
		y /= 2LL;
		for (int i = 0; i < 31; ++i) {
			if (x % 2 == 0) {
				//go -
				if (y % 2 == 0) {
					cout << "L";
				}
				else {
					cout << "D";
				}
			}
			else {
				if (y % 2 == 0) {
					cout << "U";
				}
				else {
					cout << "R";
				}
			}
			x /= 2;
			y /= 2;
		}
		cout << endl;
	}
	return 0;
}