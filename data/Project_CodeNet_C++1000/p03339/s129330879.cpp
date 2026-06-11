#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;

	vector<int> e(n), w(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'E') {
			e[i] = 1;
		}
		else {
			w[i] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		w[i] += w[i - 1];
		e[i] += e[i - 1];
	}

	int mn = e[n - 1];
	int t;
	for (int i = 1; i < n; i++) {
		t = w[i - 1];
		t += e[n - 1] - e[i];
		mn = min(mn, t);
	}
	cout << mn << endl;

	return 0;
}