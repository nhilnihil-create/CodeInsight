#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b; string s;
	cin >> a >> b >> s;
	for(int i  =0; i < s.size(); ++i){
		if(b-1!= i) cout << s[i];
		else cout << char(tolower(s[i]));
	}
	return 0;
}