#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <istream>
#include <map>
#include <set>
#include <queue>
#define rep0(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i) 
const long long INF = 1000000007;
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	/*
	/
	/
	/
	*/
	int a, b;
	cin >> a >> b;
	if ( ((2 * b) - 1) <= a) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
