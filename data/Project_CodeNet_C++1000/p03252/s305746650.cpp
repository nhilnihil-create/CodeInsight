#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
set <int >a[26], b[26];
 
int main()
{
	int n;
	string y,x;
	cin >> x >> y;
	for (int i = 0; i < x.size(); i++)
	{
		a[x[i] - 'a'].insert(y[i] - 'a');
		b[y[i] - 'a'].insert(x[i] - 'a');
	}
	for (int i = 0; i <= 25; i++)
	{
		if (a[i].size() > 1 || b[i].size() > 1)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}