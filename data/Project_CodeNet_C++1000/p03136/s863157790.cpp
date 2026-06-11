#include<iostream>
using namespace std;
int main()
{
	int n, in, sum, max;
	max = sum=0;
	cin >> n;
	while (n--)
	{
		cin >> in;
		sum += in;
		if (in > max) max = in;
	}
	sum -= max;
	if (max < sum) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
