#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> v;
	if (s[0] == '0') v.push_back(0);
	for (int i = 0; i < n; ) {
		int a = 0;
		while (i < n-1 && s[i] == s[i+1]) {
			i++;
			a++;
		}
		i++;
		a++;
		v.push_back(a);
	}
	if (v.size() % 2 == 0) v.push_back(0);
	k = min(k, (int)v.size() / 2);
	for (int i = 0; i < v.size()-1; i++) {
		v[i+1] += v[i];
	}
	v.insert(v.begin(), 0);
	int ans = 0;
	for (int i = 0; i+k*2+1 < v.size(); i += 2) {
		ans = max(ans, v[i+k*2+1] - v[i]);
	}
	cout << ans << endl;
	return 0;
}