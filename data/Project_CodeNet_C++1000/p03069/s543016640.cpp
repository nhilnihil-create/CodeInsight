#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> w(n + 1);
	for (int i = 0; i < n; i++)
		if (s[i] == '#')
			w[i + 1] = w[i] + 1;
		else
			w[i + 1] = w[i];
	int ans = 2e5;
	for (int i = 0; i <= n; i++)
		ans = min(ans, w[i] + n - i - (w[n] - w[i]));
	cout << ans << endl;
}
