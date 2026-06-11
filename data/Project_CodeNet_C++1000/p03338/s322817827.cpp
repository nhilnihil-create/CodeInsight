#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> alph(26, 0);
	int ans = 0;
	rep(i, n-1) {
		string l = s.substr(0, i+1), r = s.substr(i+1,n-i-1);
		int now = 0;
		for (int c = 'a'; c <= 'z'; c++) {
			if (l.find(c) != -1 && r.find(c) != -1) now++;
		}
		ans = max(ans,now);
	}
	cout << ans << endl;
	return 0;
}