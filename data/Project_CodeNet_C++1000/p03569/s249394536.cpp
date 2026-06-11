#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; cin >> s;
	int left=0,right=s.size()-1;
	int ans=0;
	while(left<right) {
		if(s[left]!=s[right]) {
			++ans;
			if(s[left]=='x') {
				++left;
			} else if(s[right]=='x') {
				--right;
			} else {
				cout << -1 << endl;
				return 0;
			}
		} else ++left,--right;
	}
	cout << ans << endl;
	
	return 0;
}
