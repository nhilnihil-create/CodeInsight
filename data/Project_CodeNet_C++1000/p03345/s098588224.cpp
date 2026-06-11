#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long A, B, C, K;
	cin >> A >> B >> C >> K;

	long long ans = A - B;
	if( K % 2 ) ans = -ans;

	cout << ans << endl;
}
