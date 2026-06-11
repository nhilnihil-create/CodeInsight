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
	string x,l;
	cin >> x>>l;
	 reverse(x.begin(), x.end());
	if (x ==l )
		cout << "YES";
	else
		cout << "NO";
}