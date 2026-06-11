#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
  	cin >> s >> t;
  	if(s[0]>t[0])cout << ">";
  	else if(s[0]<t[0])cout << "<";
  	else cout << "=";
  	return 0;
}