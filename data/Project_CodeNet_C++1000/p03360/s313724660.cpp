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
	int k,mm=0;
	vector<int>n(3);
	rep(i, 3)cin >> n[i];
	cin >> k;
	sort(all(n));
	mm += n[0] + n[1];
	rep(i, k) {
		n[2] *= 2;
	}

	mm += n[2];
	cout << mm << endl;
	return 0;
}
