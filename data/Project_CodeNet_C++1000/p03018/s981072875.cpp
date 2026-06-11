
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	ll ans = 0;
	int A = 0;
	for (int i=0; i < (int)s.size() - 2; i++) {
		if (s[i] == 'A') A++;
		else A = 0;

		if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
			ans += A;
			s[i] = 'B';
			s[i+1] = 'C';
			s[i+2] = 'A';
			if (A >= 2) {
				A = A - 2;
				s[i+1] = 'A';
			}
		}
	}

	cout << ans << endl;

	return 0;
}