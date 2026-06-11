#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	if (N == 3)
	{
		cout << "2 5 63" << endl;
		return 0;
	}
	else if (N == 4)
	{
		cout << "2 5 20 63" << endl;
		return 0;
	}
	
	int a, b;
	// aは3の倍数を出力する回数
	// bは(2の倍数) && !(3の倍数)を出力する回数
	if (N % 2 == 1)
	{
		a = min((N / 4 - 1) * 4 + 3, 9999);
		b = N - a;
	}
	else
	{
		a = min((N - 1) / 4 * 4, 10000);
		b = N - a;
	}
	for (int i = 1; i <= a; i++)
		cout << 3 * i << " ";

	int cnt = 0, x = 2;
	while (true)
	{
		if (x % 3 == 0)
		{
			x += 2;
			continue;
		}
		else
		{
			cout << x << (cnt != b - 1 ? " " : "");
			if (cnt == b - 1)
				break;
			else
				cnt++;
			x += 2;
		}
	}
}