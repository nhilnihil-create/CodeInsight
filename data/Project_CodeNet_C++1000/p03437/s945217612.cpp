 #include <bits/stdc++.h>
using namespace std;

int main()
{
	long long X, Y;
	cin >> X >> Y;

	long long ans = -1;
	if( X % Y ) {
		long long n = 2;
		while( X * n % Y ==  0 ) n++;
		ans = X * n;
	}

	cout << ans << endl;
}
