#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	ll sum = 0;
	int ara[n], ara1[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ara[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> ara1[i];
		if (ara[i] > ara1[i])
		{
			sum += ara[i] - ara1[i];
		}
	}
	cout << sum << endl;
	return 0;
}