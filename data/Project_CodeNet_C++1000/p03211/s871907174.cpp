#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;

int main() {
	string s;
	cin >> s;
	int x = INF;
	for (int i = 0; i < s.size()-2; i++) {
		string sub = s.substr(i, 3);
		int now = stoi(sub);
		x = min(x, abs(753-now));
	}
	cout << x << endl;
	return 0;
}