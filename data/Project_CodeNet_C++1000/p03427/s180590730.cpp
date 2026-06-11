#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int size = (int) s.length();
	char first = s[0];
	if (size == 1) {cout << s; return 0;}
	bool flag = true;
	
	for (int i =1; i< size; i++){
		if (s[i] != '9') flag = false;
	}
	if (!flag) {cout << (int) (first-'0')-1+(size-1)*9; return 0;}
	else {cout << (int) (first-'0') + (size-1)*9; return 0;}
	
	

	
 }
