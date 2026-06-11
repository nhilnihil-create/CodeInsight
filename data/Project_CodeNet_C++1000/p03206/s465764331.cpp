#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int d;

	cin >> d;
	string ans = "Christmas";

	if(d < 25)
		ans += " Eve"; 
	if (d < 24)
		ans += " Eve";
	if (d < 23)
		ans += " Eve";
	cout << ans << endl;
}
