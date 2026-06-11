#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int64_t	A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	if (A + B < 2 * C)
		cout << X * A + Y * B << endl;
	else if (X < Y && B < 2 * C) 
		cout << X * 2 * C + (Y - X) * B << endl;
	else if (X > Y && A < 2 * C) 
		cout << (X - Y) * A + Y * 2 * C << endl;
	else
		cout << max(X, Y) * 2 * C << endl;
}
