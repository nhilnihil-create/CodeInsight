#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	rep(i, S.size())
	for (int j=i; j<=S.size(); j++){
		string T = S.substr(0,i) + S.substr(j,S.size()-j);
		if (T=="keyence") {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
