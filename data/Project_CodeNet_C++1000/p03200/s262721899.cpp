#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	ll ans = 0;
	int b = 0;
	rep(i,S.size()){
		b += S[i]=='B';
		if (S[i] == 'W') ans += b;
	}
	cout << ans << endl;
	return 0;
}
