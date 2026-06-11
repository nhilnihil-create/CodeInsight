#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
  	cin >> s;
  	sort(&s[0],&s[2]+1);
  	cout << (s=="abc"?"Yes":"No");
  	return 0;
}