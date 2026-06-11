#include<cstdio>
#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
int main(){
	int o = 0;
	string s;
	cin >> s;
	for(int i = 0; i <= s.length(); i++){
		if(s[i] == 'o'){
			o++;
		}
	}
	if(15 - s.length() >= 8 - o){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}