#include<bits/stdc++.h>
using namespace std;



string solve(string str)
{	
	int c = 0;
	int len = str.length();
	for(int i=0;i<len;i++) {
		if(i == 0) {
			if(str[i] != 'A') {
				return "WA";
			}
		} else {
			if(str[i] == 'C') {
				if(c != 0) {
					return "WA";
				}
				//cout << i << endl;
				if(i < 2 || i > len-2) {
					return "WA";
				} else {
					c++;
				}
			} else {
				if(str[i] != tolower(str[i])) {
					return "WA";
				}
			}
		}
	}
	
	if(c == 0) {
		return "WA";
	}
	return "AC";
	
}
			
		

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	cout << solve(str) << endl;
	return 0;
}
