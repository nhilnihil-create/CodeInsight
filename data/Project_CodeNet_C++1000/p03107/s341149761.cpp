#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	string s;
	cin >> s;
	int ans = 0;
	while (true){
		if (s.find("0") == string::npos || s.find("1") == string::npos) break;
		for (int i = 0; i < s.size() - 1; i++){
			if (s[i] != s[i + 1]){
				ans += 2;
				string a = s.substr(0, i);
				string b;
				if (i == s.size() - 1) b = "";
				else b = s.substr(i+2);
				s = a + b;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
