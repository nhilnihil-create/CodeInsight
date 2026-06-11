#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int k;
	cin >> s >> k;
	for(int i =0; i<(int)s.length();i++){
		if(s[i]=='1' && k==i+1) {cout << 1; return 0;}
		if(s[i]!='1') {cout << s[i]; return 0;}
	}
		
 }
