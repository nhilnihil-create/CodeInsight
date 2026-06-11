#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long int LLI;
int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	int tmp, right = 0, left = 0, sum = 0;
	for(int i = 0; i < m; i++)
	{
		cin >> tmp;
		if( tmp == x )
			sum++;
		else if( tmp < x )
			left++;
		else
			right++;
	}
	if( left < right )
		cout << sum + left;
	else cout << sum + right;
}
