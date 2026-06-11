#include <iostream>
#include <vector>
using namespace std;
typedef long long int LLI;

int main()
{
	int n, tmp;
	cin >> n;
	tmp = n;
	int sum = 0;
	while( tmp > 0 )
	{
		sum += tmp % 10;
		tmp /= 10;
	}
	if( n % sum == 0 )
		cout << "Yes";
	else
		cout << "No";
}