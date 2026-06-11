#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int N = S.size();
	int ans = N;
	int ptn = 0;
	int cnt = 0;
	for( int i = 0; i < N; i++ ) {
		if( S[i] - '0' != ptn ) cnt++;
		ptn = 1 - ptn;
	}
	ans = min( ans, cnt );
	ptn = 1;
	cnt = 0;
	for( int i = 0; i < N; i++ ) {
		if( S[i] - '0' != ptn ) cnt++;
		ptn = 1 - ptn;
	}
	ans = min( ans, cnt );

	cout << ans << endl;
}
