#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n);
using namespace std;
int main()
{
	MaRiaMa;
	int n, k,i=1,g=0;
	int j = 1;
	bool m = false;
	cin >> n >> k;
	while (g<n)
	{
		j = i;
		i *= 2;
		j += k;
		if (i > j)
		{
			break;
		}
		g++;
	}
	n -= g;
	i = 1;
	while (g!=0)
	{
		i *= 2;
		g--;
	}
	while (n != 0)
	{
		i += k;
		n--;
	}
	cout << i;
}