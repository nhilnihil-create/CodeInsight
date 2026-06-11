#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<pair<string, string>, ll> m;

vector<pair<string, string>> f(const string& s) {
	vector<pair<string, string>> res;
	int N = s.size();
	for (int i = 0; i < (1 << N); i++) {
		string l, r;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) l += s[j];
			else r += s[j];
		}
		res.emplace_back(l, r);
	}
	return res;
}

int main() {
	int N; cin >> N;
	string s; cin >> s;
	string l = s.substr(0, N);
	string r = s.substr(N, N);
	reverse(r.begin(), r.end());
	for (auto& x : f(l)) {
		m[x]++;
	}
	ll res = 0;
	for (auto& x : f(r)) {
		res += m[x];
	}
	cout << res << endl;
}