#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int n;
	cin >> n;
	set<string> words;
	string rec[102];
	rep(i, n) {
		string w; cin >> w;
		words.insert(w);
		rec[i] = w;
	}
	bool ok = true;
	if (words.size() < n) ok = false;
	rep(i, n-1) {
		if (rec[i].back() != rec[i+1].front()) ok = false;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}