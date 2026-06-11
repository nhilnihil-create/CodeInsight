#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
      	string s;
	cin >> s;

	reverse(s.begin(), s.end());

	string ans = s.substr(8, s.size() - 8);
	
	reverse(ans.begin(), ans.end());

	cout << ans << endl;

	return 0;
}
