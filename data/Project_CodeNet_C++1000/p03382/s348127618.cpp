#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string> 
#include <map>
#include <iomanip>
#include <list>
#include <stack>

using namespace std;


typedef int INT;
#define int long long

INT main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << a[n - 1] << " ";
	int b, c;
	b = a[n - 1] / 2;
	c = b;
	if (a[n - 1] % 2 == 1)
		c = b + 1;
	int mmax = -1, r = -1;
	for (int i = 0; i < n - 1; i++)
	{
		if (abs(c - a[i]) < mmax || mmax == -1)
		{
			mmax = abs(c - a[i]);
			r = a[i];
		}
		if (abs(b - a[i]) < mmax || mmax == -1)
		{
			mmax = abs(b - a[i]);
			r = a[i];
		}
	}
	cout << r;


	return 0;
}