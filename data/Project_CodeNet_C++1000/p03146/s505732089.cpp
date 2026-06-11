#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int s;
	cin >> s;
	vector<int> a;
	a.push_back(s);
	set<int> st;
	st.insert(s);
	for (int i = 1; i <= 1000000; ++i) {
		if (a[i-1] % 2 == 0) {
			a.push_back(a[i-1] / 2);
		} else {
			a.push_back(3 * a[i-1] + 1);
		}
		if (st.count(a[i]) == 0) {
			st.insert(a[i]);
		} else {
			cout << i + 1 << '\n';
			break;
		}
	}

	return 0;
}
