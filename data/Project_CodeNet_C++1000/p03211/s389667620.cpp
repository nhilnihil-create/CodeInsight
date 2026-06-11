#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	int ans = 1e9;
	for (int i = 0; i+2 < s.size(); i++)
	{
		string t = s.substr(i, 3);
		ans = min(ans, abs(753 - stoi(t)));
	}
	cout << ans << endl;
	return 0;
}
