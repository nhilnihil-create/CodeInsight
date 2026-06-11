#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 1005;

int x[MAXN], y[MAXN];

int n, chk;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	chk = ((x[1] + y[1]) % 2 + 2) % 2;
	for (int i = 2; i <= n; i++)
		if (chk != ((x[i] + y[i]) % 2 + 2) % 2)
		{
			cout << -1 << endl;
			exit(0);	
		}
	cout << (chk == 0 ? 32 : 31) << endl;
	if (chk == 0)
		cout << 1 << " ";
	for (int i = 30; i >= 0; i--)
		cout << (1 << i) << " ";
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		int X = x[i], Y = y[i];
		if (chk == 0)
		{
			cout << "R";
			--X;
		}
		int val = (1 << 30) - 1;
		for (int j = 30; j >= 0; j--, val >>= 1)
		{
			if (1ll * abs(X + (1 << j)) + abs(Y) <= val)
			{
				cout << "L";
				X += (1 << j);
			}
			else if (1ll * abs(X - (1 << j)) + abs(Y) <= val)
			{
				cout << "R";
				X -= (1 << j);
			}
			else if (1ll * abs(X) + abs(Y + (1 << j)) <= val)
			{
				cout << "D";
				Y += (1 << j);
			}
			else if (1ll * abs(X) + abs(Y - (1 << j)) <= val)
			{
				cout << "U";
				Y -= (1 << j);
			}
		}
		cout << endl;
	}
	return 0;
}
