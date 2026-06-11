#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long LINF = 1LL << 60;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	string s, t; cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), greater<int>());
	rep(i, min(s.size(), t.size())) {
		if (s[i] < t[i]) {
			cout << "Yes" << endl;
			return 0;
		}
		else if (s[i] > t[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	if (s.size() >= t.size())cout << "No";
	else cout << "Yes";
}

