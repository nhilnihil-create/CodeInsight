#include <bits/stdc++.h>
using namespace std;

int main() {

	string s; cin >> s;
	int k; cin >> k;
	
	vector<string> c;
	for (int count = 1; count <= k; count++) {
		for (int j = 0; j < s.size()- count + 1; j++) {
			c.push_back(s.substr(j, count));
		}	
	}

	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());

	cout << c[k - 1] << endl;
	return 0;
}