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
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	string s;
	cin >> s;
	int su = a - 1;
	int hu = b - 1;
	while (1) {
		if (hu == d - 1) {
			break;
		}
		hu++;
		if (s[hu] == '#') {
			hu++;
			if (s[hu] == '#') {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	while (1) {
		if (su == c - 1) {
			break;
		}
		su++;
		if (s[su] == '#') {
			su++;
			if (s[su] == '#') {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	if (su < hu) {
		cout << "Yes" << endl;
		return 0;
	}
	else {
		for (int i = b-2; i < d-1; i++) {
			if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
				cout << "Yes" << endl;
				return 0;
			}
		}

	}
	cout << "No" << endl;
	
	return 0;
}