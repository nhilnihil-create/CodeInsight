#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> a( N );
	for( int i = 0; i < N; i++ ) {
		cin >> a[i];
	}

	int ans = 0;
	int cnt = 0;
	int c = -1;
	for( int i = 0; i < N; i++ ) {
		if( a[i] == c ) cnt++;
		else {
			ans += (cnt + 1) / 2;
			cnt = 0;
		}
		c = a[i];
	}
	ans += (cnt + 1) / 2;

	cout << ans << endl;
}
