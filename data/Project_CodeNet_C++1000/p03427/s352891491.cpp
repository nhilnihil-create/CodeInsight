#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	cin.exceptions(cin.failbit);

	ll n; cin >> n;
	string s = to_string(n);

	fill(s.begin(), s.end(), '9');

	int maxsum = 0;
	for (int i = 0; i < s.length(); i++) {
		for (char d = '0'; d <= '9'; d++) {
			s[i] = d;
			if (stoll(s) <= n) {
				int sum = 0;
				for (char c : s) sum += c - '0';
				maxsum = max(maxsum, sum);
			}
		}
	}
	cout << maxsum << endl;
}
