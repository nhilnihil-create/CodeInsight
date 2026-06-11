#include <bits/stdc++.h>
using namespace std;
int main() {
	string S;
	cin >> S;
	vector<int> v(3);
	v[0] = v[1] = v[2] = 0;
	for(int i = 0; i < S.length(); i++) {
		v[S[i] - int('a')]++;
	}
	bool ans = (*max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end())) <= 1;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}