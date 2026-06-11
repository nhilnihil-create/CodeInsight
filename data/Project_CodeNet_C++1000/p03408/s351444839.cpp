#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n, m;
	cin >> n;
	map<string, int> blue, red;
	set<string> wordR;
	rep(i, n) {
		string a; cin >> a; 
		blue[a]++;
		wordR.insert(a);
	} 
	cin >> m;
	rep(i, m) {
		string a; cin >> a; red[a]++;
	}
	int ans = 0;
	for (auto s: wordR) {
		ans = max(ans, blue[s]-red[s]);
	}
	cout << ans << endl;
	return 0;
}