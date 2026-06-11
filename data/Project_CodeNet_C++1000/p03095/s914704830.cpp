 #include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;

	const long long MOD = 1000000000 + 7;
	vector<long long> v( 26 );
	for( int i = 0; i < N; i++ ) {
		int n = S[i] - 'a';
		v[n]++;
	}
	long long ans = 1;
	for( int i = 0; i < 26; i++ ) {
		if( v[i] == 0 ) continue;
		ans *= v[i] + 1;
		ans %= MOD;
	}
	ans = (ans - 1 + MOD) % MOD;

	cout << ans << endl;
}
