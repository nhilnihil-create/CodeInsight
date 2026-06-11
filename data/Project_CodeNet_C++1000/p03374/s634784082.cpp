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

	int n, c;
	cin >> n >> c;
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; i++)
	{
		int b, d;
		cin >> b >> d;
		a[i] = { b, d };
	}
	sort(a.begin(), a.end());
	vector <int> msudi(n), mtudi(n);
	int mmax = 0;
	int cur = 0, t = 0;
	for (int i = 0; i < n; i++)
	{
		cur += a[i].second;
		cur -= a[i].first - t;
		t = a[i].first;
		mmax = max(mmax, cur);
		msudi[i] = mmax;
	}
	cur = 0, t = c;
	int rmax = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		cur += a[i].second;
		cur -= t - a[i].first;
		t = a[i].first;
		rmax = max(rmax, cur);
		mtudi[i] = rmax;
	}
	mmax = max(mmax, rmax);


	cur = 0; t = 0;
	for (int i = 0; i < n - 1; i++)
	{
		cur += a[i].second;
		cur -= a[i].first - t;
		t = a[i].first;
		int u = cur - a[i].first;
		u += mtudi[i + 1];
		mmax = max(u, mmax);
	}
	cur = 0; t = c;
	for (int i = n - 1; i >= 1; i--)
	{
		cur += a[i].second;
		cur -= t - a[i].first;
		t = a[i].first;
		int u = cur - (c - a[i].first);
		u += msudi[i - 1];
		mmax = max(u, mmax);
	}

	cout << mmax;

	return 0;
}