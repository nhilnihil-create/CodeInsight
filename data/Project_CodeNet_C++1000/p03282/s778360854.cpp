#include <bits/stdc++.h>


using namespace std;

int main(){
	string s;
	long long k;
	cin >> s >> k;
	for(int i=0;i<(int)s.size();i++) {
		if(s[i]=='1') {
			k--;
		}else {
			k=0;
		}
		if(k<=0) {
			cout << s[i];
			return 0;
		}
	} 
}


