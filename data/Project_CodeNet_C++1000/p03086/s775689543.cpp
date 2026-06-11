#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
char che[4] = { 'A','C','G','T' };
int main(void) {
	string s;
	cin >> s;
	ll ans = -inf;
	ll count = 0;
	for (int i = 0; i < s.size(); i++) {
		bool ok = false;
		for (int j = 0; j < 4; j++) {
			if (s[i] == che[j]) {
				ok = true;
			}
		}
		if (ok) {
			count++;
		}
		ans = max(ans, count);
		if (!ok) {
			count = 0;
		}
	}
	cout << ans << endl;
	return 0;
}