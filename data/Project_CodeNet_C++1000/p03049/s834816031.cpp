#define rep(i, n) for(int i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	int ans = 0;
	int end_A, start_B, haji_AB;
	end_A = 0, start_B = 0, haji_AB = 0;
	rep(i,n) {
		int len = s[i].size();
		rep(j,len-1) if (s[i][j]=='A' && s[i][j+1]=='B') ans++;
		if (s[i][len-1]=='A') {
			if (s[i][0]=='B') haji_AB++;
			else end_A++;
		}
		else if(s[i][0]=='B') start_B++;
	}
	if (haji_AB>=1) {
		ans += haji_AB-1;
		if (end_A>=1) {
			ans++;
			end_A--;
		}
		if (start_B>=1) {
			ans++;
			start_B--;
		}
	}
	ans += min(end_A, start_B);
	/*
	ans += min(end_A, start_B) + max(haji_AB-1,0);
	if ((end_A!=start_B) && haji_AB>=1) ans++;
	*/
	cout << ans << endl;
	return 0;
}
