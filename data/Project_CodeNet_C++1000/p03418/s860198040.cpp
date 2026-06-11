#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	LLI n, k, sum = 0;
	cin >> n >> k;
	if( k == 0 )
		cout << n*n;
	else{
		for(int i = k+1; i <= n; i++)
		{
			sum += n/i*(i-k);
			if( n % i >= k )
				sum += n % i - k+1;
		}
		cout << sum;
	}
}