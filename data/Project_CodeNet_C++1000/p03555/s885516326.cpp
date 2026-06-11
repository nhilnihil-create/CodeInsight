#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;

int main() {
	string a, b;
	cin >> a >> b;
	bool ans = false;
	if (a[0] == b[2] && a[1] == b[1] && a[2] == b[0]) ans = true;
	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
