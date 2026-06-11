#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int kInf = 1e9+19;

void Solve() {
	string s;
	cin >> s;

	int n = s.length();

	unordered_map<int, vector<int>> edges;
	vector<int> pref(n + 1);
	queue<int> Q;
	vector<int> d(n + 1, kInf);

	pref[0] = 0;

	for (int i = 0; i < s.length(); ++i) {
		pref[i+1] = pref[i] ^ (1<< (s[i] - 'a'));
		edges[pref[i+1]].push_back(i + 1);
	}
	
	Q.push(0);
	d[0] = 0;
	while(!Q.empty()) {
		int x = Q.front();
		// cerr << x << "\n";
		Q.pop();
		
		for (int j = 0; j < 27; ++j) {
			int new_pref;
			if (j == 26)
				new_pref = pref[x];
			else new_pref = pref[x] ^ (1 << j);
			auto& e = edges[new_pref];
			while (!e.empty() && x < e.back()) {
				int y = e.back();
				Q.push(y);
				d[y] = d[x] + 1;
				e.pop_back();
			}
		}
	}

	cout << d[n] << "\n";
}

int main() {
	int tests = 1;

	for (;tests; --tests) {
		Solve();
	}
}