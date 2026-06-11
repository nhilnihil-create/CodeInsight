#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	string s; cin >> s;
	int n = s.size();
	bool x = true;
	for (int i =1; i < n; i++) {
		if (s[i-1] != s[n - i - 1]) {
			x = false;
		}
	}
	if (s[0] == '1'&&s[n - 1] == '0'&&x) {
		vector<int> a;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				a.emplace_back(i);
			}
		}
		a.emplace_back(n-1);
		for (int i = 0; i < n-1; i++) {
			cout << a[(lower_bound(a.begin(), a.end(), i+1) - a.begin())]+1 << " " << i+1 << endl;
		}
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}
