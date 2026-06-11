#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		string t = s.substr(0, i);
		string u = s.substr(i, n - i);
		set<char> st;
		rep(j, i) {
			rep(k, n - i) {
				if (t[j] == u[k]) st.insert(t[j]);
			}
		}
		ans = max(ans, (int)st.size());
	}
	cout << ans << endl;
	return 0;
}