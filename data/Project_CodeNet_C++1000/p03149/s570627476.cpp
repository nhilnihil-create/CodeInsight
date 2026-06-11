#include <bits/stdc++.h>
using namespace std;

int main(){
	string s = "";
	for(int i = 0; i < 4; i++){
		string t;
		cin >> t;
		s += t;
	}
	sort(s.begin(), s.end());
	if(s == "1479") cout << "YES" << endl;
	else cout << "NO" << endl;
}