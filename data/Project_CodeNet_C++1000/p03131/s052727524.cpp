#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	long long K, A, B;
	cin >> K >> A >> B;

	long long ans1 = 1 + K;
	long long ans2 = A;
	if( A > 1 ) {
		K -= A - 1;
	}
	ans2 += K / 2 * (B - A);
	ans2 += K % 2;
	long long ans = max( ans1, ans2 );

	cout << ans << endl;
}
