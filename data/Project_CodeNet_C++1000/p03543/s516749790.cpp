//#include "stdafx.h"
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n)
using namespace std;
int main()
{
	MaRiaMa;
	int k = 1;
	string s;
	cin >> s;
	for (int i = 0; i < 4; i++)
	{

		if (s[i] == s[i + 1])
		{
			k++;
			if (k >= 3)
			{
				cout << "Yes";
				return 0;
			}
		}
		else
			k = 1;
	}
	cout << "No";
}
