#include <bits/stdc++.h>
using namespace std;

int main()
{
	int X, Y;
	cin >> X >> Y;

	int ans = -1;
	if( X % Y ) ans = X;

	cout << ans << endl;
}