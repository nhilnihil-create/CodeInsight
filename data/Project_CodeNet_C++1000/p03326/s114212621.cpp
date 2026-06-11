#include<bits/stdc++.h>

using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fast_io;
	
	int n,m;
	cin >> n >> m;

	long long array[n][3];
	long long maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i][0] >> array[i][1] >> array[i][2];
	}	


	for (int i = 0; i < 8; ++i)
	{
		string binaryRep = "";
		int copy = i;
		for (int j = 0; j < 3; j++)
		{
			binaryRep += to_string(copy%2);
			copy /= 2;
		}

		// cout << "binaryRep: " << binaryRep << endl;

		vector<long long> summations;
		for (int j = 0; j < n; j++)
		{
			long long currSum = 0;
			for (int k = 0; k < 3; k++)
			{
				if (binaryRep[k] == '0') currSum += array[j][k];
				else currSum -= array[j][k];
			}
			summations.push_back(currSum);
		}
		long long currMax = 0;
		sort(summations.begin(), summations.end());
		int done = 0;
		for (int j = n-1; j >= 0 && done < m; j--, done++)
		{
			currMax += summations[j];
		}
		maxi = max(maxi, currMax);
	}

	cout << maxi << endl;
	
	return 0;
}
