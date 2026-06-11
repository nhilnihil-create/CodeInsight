#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int N = S.size();
	int ans = 1000;
	for( int i = 0; i < N - 3 + 1; i++ ) {
		int X = 0;
		for( int j = 0; j < 3; j++ ) {
			X = X * 10 + S[i + j] - '0';
		}
		ans = min( ans, abs( X - 753 ) );
	}

	cout << ans << endl;
}
