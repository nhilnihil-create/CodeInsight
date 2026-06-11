// B - AcCepted
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin>>s;
	bool ok = true;
	if(s[0] != 'A') ok = false;
	if(s[1]<'a' || 'z'<s[1]) ok = false;
	if(s.back()<'a' || 'z'<s.back()) ok = false;
	int c = 0;
	for(int i=2; i<(int)s.size()-1; ++i)
		if(s[i] == 'C') c++;
	if(c != 1) ok = false;
	cout<< (ok? "AC":"WA") <<endl;
}
