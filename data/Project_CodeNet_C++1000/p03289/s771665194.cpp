#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	if (s[0] != 'A') {cout << "WA"; return 0;}
	int count = 0;
	for (int i = 2; i < (int) s.length() - 1; i++){
		if(s[i] == 'C') count++;
	}
	if (count!=1) {cout << "WA"; return 0;}
	
	for(int i = 1; i<(int) s.length(); i++){
		if(s[i] == 'C' && (i > 1 && i<(int) s.length()-1)) continue;
		else if(!('a'<= s[i]  && s[i] <= 'z')) {cout << "WA"; return 0;}
	}
	cout << "AC";
 }
