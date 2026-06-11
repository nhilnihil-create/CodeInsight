#include<iostream>

using namespace std;

int main()
{
	int n, max = 0, sum = 0;
	cin >> n;
	for (int i = 0, j;i < n;i++)
	{
		cin >> j;
		sum += j;
		if (max < j)
			max = j;
	}
	if (max < sum - max)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}