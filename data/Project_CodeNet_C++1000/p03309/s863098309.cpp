#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL);


int main()
{
	FAST_IO;

	int n;
	cin >> n;

	long long array[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
		array[i] -= (i+1);
	}

	sort(array, array+n);

	long long b;

	if (n%2)
	{
		b = array[n/2];
	}
	else
	{
		b = (array[n/2] + array[n/2 - 1])/2;
	}

	long long answer = 0;
	for (int i = 0; i < n; ++i)
	{
		answer += abs(array[i] - (b));
	}
	cout << answer << endl;

	return 0;
}