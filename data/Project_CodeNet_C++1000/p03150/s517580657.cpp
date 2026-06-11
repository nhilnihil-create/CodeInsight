#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
	string S;
	cin >> S;

	rep(i,7)
		if(S.substr(0,i)+S.substr(S.size()-7+i,7-i) == "keyence") {
			cout << "YES" << endl;
			return 0;
		}
	
	cout << "NO" << endl;
}