#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	string S;
	cin >> S;
	vector<char> T(Q);
	vector<int> D(Q);
	char c;
	for (int i = 0; i < Q; i++) {
		cin >> T[i] >> c;
		if (c == 'L') {
			D[i] = 0;
		}
		else {
			D[i] = 1;
		}
	}
	
	int l = 0;
	int r = N + 1;
 
	for (int i = Q - 1; i >= 0; i--) {
		if (D[i] == 0) {
			if (S[l + 1 - 1] == T[i]) {
				l++;
			}
 
			if (r <= N) {
				if (S[r - 1] == T[i]) {
					r++;
				}
			}
		}
		else {
			if (S[r - 1 - 1] == T[i]) {
				r--;
			}
			if (l >= 1) {
				if (S[l - 1] == T[i]) {
					l--;
				}
			}
		}
		if (l >= r)break;
 
	}
	//cerr << l << " " << r << endl;
	int res = N - l - (N + 1 - r);
	res = max((int)0, res);
 
	cout << res << endl;
}