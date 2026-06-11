#include <iostream>
using namespace std;
int main()
{
	long long int n, k, sum;
	cin >> n >> k;
	sum = (n-1)/(k-1);
	if( (n-1)%(k-1) != 0 )
		sum++;
	cout << sum;
}