#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL);


int main()
{
	FAST_IO;

	int n;
	cin >> n;

	int array[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
	}

	int maxi = abs(array[0] - array[1]);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				maxi = max(maxi, abs(array[i] - array[j]));
		}
	}

	cout << maxi << endl;

	return 0;
}