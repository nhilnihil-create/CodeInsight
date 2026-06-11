#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;cin >> s;
  	int m=(s[5]-'0')*10+(s[6]-'0');
  	cout << (m<=4?"Heisei":"TBD");
  	
  	return 0;
}