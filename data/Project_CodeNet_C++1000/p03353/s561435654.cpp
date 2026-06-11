#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	set<string> sub;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= k && i + j - 1 < n; j++)
			sub.insert(s.substr(i, j));

	auto it = sub.begin();
	while (--k)
		it++;
	cout << *it << endl;
}
