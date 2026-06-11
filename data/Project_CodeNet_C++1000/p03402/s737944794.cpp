#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
////////////////////////////////////////

int main() {
	int A, B;
	cin >> A >> B;
	char key[100][100];
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 100; ++j) {
			key[i][j] = '#';
		}
	}
	for (int i = 50; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			key[i][j] = '.';
		}
	}
	int i = 0;
	int j = 0;
	int cnt1 = 0;
	while (cnt1 < A-1) {
		key[i][j] = '.';
		j += 2;
		cnt1++;
		if ( j >= 100) {
			if (i % 2 == 0)j = 1;
			else j = 0;
			i+=2;
		}
	}
	int k = 99;
	int l = 0;
	int cnt2 = 0;
	while (cnt2 < B - 1) {
		key[k][l] = '#';
		l += 2;
		cnt2++;
		if (l >= 100) {
			if (k % 2 == 1) {
				l = 1;
			}
			else {
				l = 0;
			}
			k-=2;
		}
	}
	cout << 100 << " " << 100 << endl;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; ++j) {
			cout << key[i][j];
		}
		cout << endl;
	}
	return 0;
}
