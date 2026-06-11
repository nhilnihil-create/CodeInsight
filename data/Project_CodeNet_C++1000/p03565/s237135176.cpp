#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S, T;
	cin >> S >> T;

	ll tlen = T.size();
	ll slen = S.size();

	bool is_rest = false;
	string ans = S;

	rep(i, slen-tlen+1) {
		if (S[i] == '?' || S[i] == T[0]) {
			bool flg = true;
			string temp;

			rep(j, tlen) {
				if (S[i + j] != '?' && S[i+j] != T[j]) {
					flg = false;
					break;
				}
			}
			if (flg) {
				is_rest = true;
				rep(j, slen) {
					if (j < i || (i + tlen) <= j) {
						if (S[j] == '?') ans[j] = 'a';
						else ans[j] = S[j];
					}
					else {
						ans[j] = T[j - i];
					}
				}
			}
		}
	}
	
	if(is_rest) cout << ans << endl;
	else cout << "UNRESTORABLE" << endl;

	return 0;
}