#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int w;
	cin >> s >> w;
	
	int i = 0;
	string ans = "";
	while (i < s.size()) {
		ans.push_back(s[i]);
		i += w;
	}
	cout << ans << endl;
	return 0;
}