#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef struct _data {
	int x;
	int y;
} data;

int  main()
{
	int a,b,x;
	cin >> a >> b >> x;
	if (a == x)
	{
		cout << "YES\n"; return 0;
	}
	else if (a < x &&  a + b >= x)
	{
		cout << "YES\n"; return 0;
	}
	cout << "NO\n";
	return (0);
}
