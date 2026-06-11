#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;

	int ans = 0;
	rep(i,S.size()) ans += int(S[i]-'0');
	rep(i,S.size()) {
		int tmp = int(S[i]-'0') - 1 + 9*(S.size()-i-1);
		rep(j,i) tmp += int(S[j]-'0');
		ans = max(ans,tmp);
	}
	cout << ans << endl;

	return 0;
}
