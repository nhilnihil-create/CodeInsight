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
	int x;
	int ans = 0;
	cin >> x;
	for (int i = 111; i < 1000; i += 111) {
		if (x == i) {
			ans = i;
			break;
		}
		else {
			if (x <= i) {
				ans = i;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}