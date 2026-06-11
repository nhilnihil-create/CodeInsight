#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long int tmp, sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		sum += tmp;
	}
	cout << sum - n;
}