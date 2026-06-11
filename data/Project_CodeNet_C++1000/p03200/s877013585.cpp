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
	string s;
	cin >> s;
	std::ifstream in("in10.txt");
	std::cin.rdbuf(in.rdbuf());
	ll ite = 0;
	ll ans = 0;
	for (long i = 0; i < s.size(); i++)
	{
		if (s[i] == 'W')
		{
			ans += i - ite;
			ite++;
		}
	}
	cout << ans << endl;
	return (0);
}
