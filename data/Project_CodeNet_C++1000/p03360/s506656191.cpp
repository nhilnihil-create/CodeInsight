#include <iostream>
using namespace std;
typedef long long int LLI;
LLI pow(LLI base, LLI exp)
{
	LLI ans = 1;
	for(int i = 0; i < exp; i++)
		ans *= base;
	return ans;
}
int main()
{
	LLI arr[3], k, max = 0, sum = 0;
	cin >> arr[0] >> arr[1] >> arr[2] >> k;
	for(int i = 0; i < 3; i++)
	{
		sum += arr[i];
		if( arr[i] > max )
			max = arr[i];	
	}
	sum -= max;
	sum += pow(2,k)*max;
	cout << sum;
}