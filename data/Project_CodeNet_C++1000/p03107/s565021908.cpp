#include <cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	string s;
	cin >> s;
	ll zerocount = 0;
	ll onecount = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			onecount++;
		}
		else {
			zerocount++;
		}
	}
	cout << 2 * min(onecount, zerocount) << endl;
	return 0;
}
