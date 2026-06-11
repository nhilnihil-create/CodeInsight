#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	int current = 0;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			current++;
		}
		else {
			ans = max(ans, current);
			current = 0;
		}
		if (i == s.size() - 1 ) {
			if (current > ans) {
				ans = current;
			}
		}
	
	}
	cout << ans;
}