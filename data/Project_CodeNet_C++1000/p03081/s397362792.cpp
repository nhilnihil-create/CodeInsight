#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int, int> P;
string s; 
char t[200006], d[200006];
int n, q; 
int simul(int x) {
	rep(i, q) {
		if (t[i] == s[x]) {
			if (d[i] == 'L')x--; else x++;
			if (x < 0 || x == n)return x;
		}
	}
	return x;
}

signed main() {
	cin >> n >> q;
	cin >> s;
	rep(i, q)cin >> t[i] >> d[i];

	int lb = -1, ub = n;
	while (ub - lb > 1) {
		int mi = (ub + lb) / 2;
		if (simul(mi) == -1)lb = mi;
		else ub = mi;
	}
	int lb2 = -1, ub2 = n;
	while (ub2 - lb2 > 1) {
		int mi = (ub2 + lb2) / 2;
		if (simul(mi) == n)ub2 = mi;
		else lb2 = mi;
	}
	cout << n - (lb + 1) - (n - ub2) << endl;
}