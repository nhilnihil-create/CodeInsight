#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	char s[5]; cin >> s;
	if(strlen(s)==2) cout << s << endl;
	else{
		for(int i=2;i>=0;i--) cout << s[i];
		cout << endl;
	}
	return 0;
}