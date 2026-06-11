#include<bits/stdc++.h>
using namespace std;
void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int main()
{
	//c_p_c();
	int t;
	cin >> t;
	int ti = 0, xi = 0, yi = 0;
	bool b = false;
	while (t--) {
		int t, x, y;
		cin >> t >> x >> y;
		int td = t - ti;
		int diff = abs(x - xi) + abs(y - yi);

		if (diff <= td && td % 2 == diff % 2)
		{
			b = true;

		}
		else
		{
			cout << "No";
			return 0;
		}
		ti = t;
		xi = x;
		yi = y;
	}
	if (b)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}