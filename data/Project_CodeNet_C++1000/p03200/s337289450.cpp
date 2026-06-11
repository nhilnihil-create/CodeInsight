#include<bits/stdc++.h>
using namespace std;
 
int main () {
	string s;
	cin >> s;
	int j=0;
	long long ans=0;
	for (int i=0; i<(int)s.length(); i++) {
		if (s[i] == 'W') {
			ans += i-j;
			j++;
		}
	}
	cout << ans;
} 