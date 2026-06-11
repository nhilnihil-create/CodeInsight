#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	string s;
	cin >> s;
	if (s.size() <= 7) {
		cout << "YES" << endl;
	}
	else {
		int lose = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'x') {
				lose++;
			}
		}
		if (lose >= 8) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}