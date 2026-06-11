//#include "stdafx.h"
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
	double x;
	int n;
	cin >> n;
	while(n!=0)
	{
		x = sqrt(n);
		if (x != int(sqrt(n)))
		{
			n--;
                        x=0;
		}
		else
		{
			cout << n;
			return 0;
		}
	}
}