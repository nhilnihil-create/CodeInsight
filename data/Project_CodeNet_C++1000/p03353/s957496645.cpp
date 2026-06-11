#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	int l = s.size();
	set<string> se;
	for (char c = 'a'; c <= 'z'; c++) {
		for (int i = 0; i < l; i++) {
			if (s[i] == c) {
				string t;
				for (int j = i; j < l; j++) {
					t += s[j];
					se.insert(t);
					if (j - i + 1 >= k) {
						break;
					}
				}
			}
		}
		if (se.size() >= k) {
			break;
		}
	}
	auto itr = se.begin();
	for (int i = 0; i < k - 1; i++) {
		itr++;
	}
	cout << *itr << endl;
	return 0;
}