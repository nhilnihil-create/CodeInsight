#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s;
	cin >> s;

	ll N = s.size();

	string dummy = "";
	for (int ii = 0; ii < N; ++ii){
		if (ii < N - 1){
			if ( (s[ii] == 'B') && (s[ii+1] == 'C') ){
				dummy += 'D';
				++ii;
			} else {
				dummy += s[ii];
			}
		} else {
			dummy += s[ii];
		}
	}

	ll ans = 0;
	ll acnt = 0;
	for (int ii = 0; ii < dummy.size(); ++ii){
		if (dummy[ii] == 'A'){
			acnt++;
		} else if (dummy[ii] == 'D') {
			ans += acnt;
		} else {
			acnt = 0;
		}
	}

	cout << ans << "\n";

	return 0;
}
