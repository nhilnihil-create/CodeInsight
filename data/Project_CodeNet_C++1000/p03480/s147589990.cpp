#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	string s;
	cin >> s;
	int m = s.length(), n = m;
	for (int i = 1; i < s.length(); ++i){
		if (s[i] != s[i-1]){
			m = min(max(i,n-i),m);
		}
	}
	cout << m << "\n";	
	return 0;
}
