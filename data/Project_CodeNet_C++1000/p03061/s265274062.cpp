#include <bits/stdc++.h>
#include<string.h>
#include <algorithm>
#include<math.h>
#include<vector>
#include <queue>
#include <deque> 
#define ll long long
#define M 1000000007 
#define MM 998244353
using namespace std;
 
int main()
{
	long long int n, temp;

	cin >> n;

	long long int a[n], left[n], right[n];
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	left[0] = a[0];
	right[n - 1] = a[n - 1];

	for (int i = 1; i < n; i++)
	{
		left[i] = __gcd(left[i - 1], a[i]);
	}

	for (int i = n - 2; i >= 0; i--)
	{
		right[i] = __gcd(right[i + 1], a[i]);
	}

	long long int ans = max(left[n - 2], right[1]);

	for (int i = 1; i < n - 1; i++)
	{
		temp = __gcd(left[i - 1], right[i + 1]);
		ans = max(ans, temp);
	}

	cout << ans;

    return 0;
}