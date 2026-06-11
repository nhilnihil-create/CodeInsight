#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	int A[100005];
	int maxv = 0;	
	cin >> N;
	for ( int i = 0; i < N; i++ ) {
		cin >> A[i];
		maxv = max(A[i], maxv);
	}
	int ans = -1, close = maxv;
	for ( int i = 0; i < N; i++ ) {
		int val = min(abs(maxv / 2 - A[i]), abs((maxv - 1) / 2 - A[i]));
		if ( close > val ) {
			close = val;
			ans = A[i];
		}
	}

	cout << maxv << " " << ans << endl;

	return (0);
}
