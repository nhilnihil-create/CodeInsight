#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	string s;
	cin >> s;
	int ans = 0;
	rep(i, s.size()) {
		for (int j = 0; i+j <= s.size(); j++) {
			string now = s.substr(i, j);
			bool ok = true;
			rep(k, j) {
				char c = now[k];
				if(c!='A'&&c!='T'&&c!='G'&&c!='C') ok = false;
			}
			if (ok) ans = max(ans, j);
		}
	}
	cout << ans << endl;
}