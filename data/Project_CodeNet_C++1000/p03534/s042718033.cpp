#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define rep_r(i,s,n)for(int i = n-1;i>=s;i--)
#define rep_re(i,s,n)for(int i = n;i>=s;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_N = 100001;

ll x[3];
int main() {
	string s; cin >> s;
	if (s.size() == 1 || (s.size() == 2 && s[0] != s[1])) {
		cout << "YES" << endl;
		return 0;
	}

	rep(i, 0, s.size()) {
		if (s[i] == 'a')x[0]++;
		else if (s[i] == 'b')x[1]++;
		else if (s[i] == 'c')x[2]++;
	}

	sort(x, x + 3);

	if (x[0] == 0) {
		cout << "NO" << endl;
	}
	else {
		x[1] -= x[0];
		x[2] -= x[0];
		if (x[1] == 0 && x[2] == 0 ||
			x[1] == 0 && x[2] == 1 ||
			x[1] == 1 && x[2] == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}