#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	bool ans = true;
	if(s[0] != 'A') ans = false;
	int c = 0;
	for(int i = 2; i < s.size()-1; i++){
		if(s[i] == 'C') c++;
	}
	if(c != 1) ans = false;
	rep(i, s.size()){
		if(s[i] == 'A' || s[i] == 'C') continue;
		if(isupper(s[i])) ans = false;
	}
	if(ans) cout << "AC" << endl;
	else cout << "WA" << endl;
	return 0;
}
