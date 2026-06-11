#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, string> P;

void solve(long long N, string S){
	map<P, ll> m;
	for (ll i = 0; i < 1<<N; i++) {
		string s1 = "", s2 = "";
		for (ll j = 0; j < N; j++) {
			if (i>>j&1) s1 += S[j]; else s2 += S[j];
		}
		// cout << s1 << " " << s2 << "\n";
		m[P(make_pair(s1, s2))]++;
	}
	// cout << m[P(make_pair("c", "aba"))] << "\n";
	ll res = 0;
	for (ll i = 0; i < 1<<N; i++) {
		string s1 = "", s2 = "";
		for (ll j = 2*N-1; j >= N; j--) {
			if (i>>(2*N-1-j)&1) s1 += S[j]; else s2 += S[j];
		}
		// cout << s1 << " " << s2 << "\n";
		res += m[P(make_pair(s1, s2))];
	}
	cout << res << "\n";
}

int main(){
	string S;
	long long N;
	scanf("%lld",&N);
	cin >> S;
	solve(N, S);
	return 0;
}
