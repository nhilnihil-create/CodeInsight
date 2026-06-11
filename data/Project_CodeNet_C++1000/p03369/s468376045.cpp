#include <bits/stdc++.h>

using namespace std;
#define ll long long 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int x=0;
	for (int i=0; i<s.size(); i++) {
		if (s[i]=='x') x++;
	}
	cout << 700+(3-x)*100;
	return 0;	
}