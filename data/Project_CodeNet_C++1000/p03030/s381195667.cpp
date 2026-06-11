#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<tuple<string, int, int>> t;
	for (int i = 0; i < n; i++) {
		string  s; int p; cin >> s >> p;
		t.push_back({ s,-p,i + 1 });
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < n; i++) {
		cout << get<2>(t[i]) << endl;
	}
	return 0;
}