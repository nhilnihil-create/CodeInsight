#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	map<string,bool> m;
	m[v[0]] = 1;
	bool d = 1;
	for (int i = 1; i < n; ++i) {
		if (v[i][0] != v[i - 1][(int)v[i - 1].size() - 1] || m[v[i]]) {
			d = 0;
		}
		m[v[i]] = 1;
	}
	if (d) {
		cout << "Yes";
	}else {
		cout << "No";
	}
}
