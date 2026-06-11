#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;
lli k;

int main(void){
	cin >> s >> k;
	while(s[0] == '1'){
		k--;
		if(k == 0){
			cout << s[0] << endl;
			return 0;
		}
		s = s.substr(1);
	}
	cout << s[0] << endl;

	return 0;
}
