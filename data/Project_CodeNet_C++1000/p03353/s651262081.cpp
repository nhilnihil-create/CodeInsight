#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int k; cin >> k;
	int p, q;
	q = s.size();
	p = min(10, q);
	vector<string> c;
	for (int count = 1; count <= p; count++) {
		for (int j = 0; j < s.size() - count + 1; j++) {
			c.push_back(s.substr(j, count));
		}
	}

	// 辞書順の小さい順にソート
	sort(c.begin(), c.end());

	// 重複要素を削除
	c.erase(unique(c.begin(), c.end()), c.end());

	cout << c[k - 1] << endl;
	return 0;
}