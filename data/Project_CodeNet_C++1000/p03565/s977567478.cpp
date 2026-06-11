#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	string s, t;
	cin >> s >> t;
	vector<string> st;
	int ns = s.size();
	int nt = t.size();
	rep(i, ns - nt + 1) {
		bool ok = true;
		rep(j, nt) {
			if (s[i+j] == '?') continue;
			if (s[i+j] != t[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			string now = s;
			rep(k, nt) {
				now[k+i] = t[k];
			}
			rep(k, ns) if (now[k] == '?') now[k] = 'a';
			st.push_back(now);
		}
	}
	if (st.size() > 0) {
		sort(all(st));
		cout << st[0] << endl;
	} else {
		cout << "UNRESTORABLE" << endl;
	}
	return 0;
}