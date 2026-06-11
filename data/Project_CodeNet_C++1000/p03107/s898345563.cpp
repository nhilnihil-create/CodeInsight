#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	int now = 0;
	int ans = 0;
	while (now < S.size()-1 && S.size()>0) {
		if (S[now] != S[now+1]) {
			S.erase(now,2);
			now = max(0,now-1);
			ans += 2;
		}
		else now++;
	}

	cout << ans << endl;

	return 0;
}
