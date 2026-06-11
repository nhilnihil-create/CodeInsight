// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	
	int ans1 = 0, ans2 = 0;
	
	for(int i = 0; i < s.length(); i++) {
		if(i & 1) {
			if(s[i] != '0') ans1++;
			if(s[i] != '1') ans2++;
		}
		else {
			if(s[i] != '1') ans1++;
			if(s[i] != '0') ans2++;
		}
	}

	cout << min(ans1, ans2);

	return 0;
}
