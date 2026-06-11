#include<iostream>
#include<array>
#include<vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <tuple>
#include<cmath>
#include<queue>
#include <climits>

using lli = long long int;
using namespace std;
int inf = 1000000007;

int N, Q;
string s;
char t, d;

bool solve(vector<tuple<char, char>> q, int x) {
	char now = s[x];
	for (int i = 0; i < Q; i++) {
		tie(t, d) = q[i];
		if (t == now) {
			if (d == 'R')x++;
			else x--;
		}
		if (x == -1 || x == N) return false;
		now = s[x];
	}
	return true;
}

int main() {
	cin >> N >> Q;
	cin >> s;
	vector<tuple<char, char>> quary(Q);
	for (int i = 0; i < Q; i++) {
		cin >> t >> d;
		quary[i] = make_tuple(t, d);
	}
	//左端と右端探す
	int ok = -1;
	int ng = N;
	while (ng - ok != 1) {
		int x = (ng + ok) / 2;
		if (solve(quary, x))ok = x;
		else ng = x;
	}
	int left = ok;
	ok = N - 1;
	ng = -1;
	while (ok - ng != 1) {
		int x = (ng + ok) / 2;
		if (solve(quary, x))ok = x;
		else ng = x;
	}
	cout << max(0, left - ok + 1) << endl;
}
