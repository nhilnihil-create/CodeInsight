#include<bits/stdc++.h>

using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fast_io;
	
	int n,k;
	cin >> n >> k;

	int array[n];
	int indexOne;
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
		if (array[i] == 1)
			indexOne = i;
	}

	int answer = 0;
	int remainder = 0;
	answer += (indexOne/(k-1));
	if (indexOne%(k-1)) remainder += (indexOne%(k-1));

	answer += (n - indexOne-1)/(k-1);
	if ((n-indexOne-1)%(k-1)) remainder += ((n-indexOne-1)%(k-1));

	answer += remainder/k;
	remainder %= k;
	if (remainder) answer++;

	cout << answer << endl;
	
	return 0;
}
