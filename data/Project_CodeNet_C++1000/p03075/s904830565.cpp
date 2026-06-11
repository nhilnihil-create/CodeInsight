#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	vector<int> dis(5);
	for (int i = 0; i < 5; i++)
		cin >> dis[i];
	int k;
	cin >> k;
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (j != i)
			{
				if (abs(dis[i] - dis[j]) > k)
				{
					cout << ":(" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yay!" << endl;
	return 0;
}