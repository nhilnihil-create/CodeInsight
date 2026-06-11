#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int a, b, c;
	
	cin >> a >> b >> c;
	int ans =  0;

	ans += max({a, b, c}) * 10;
	ans += min({max(a, b), max(b, c), max(a, c)});
	ans += min({a, b, c});
	cout << ans << endl;
}

