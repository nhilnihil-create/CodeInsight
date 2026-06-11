#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int k = 0;
	int mini = 1000000002;
	long long int res = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		k += a > b;
		if (a > b)
		{
			mini = min(mini, b);
		}
		res += b;
	}
	cout << (k == 0 ? 0 : res - mini);
	//system("pause");
	return 0;
}
