#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, A, B;
	cin >> N >> A >> B;
	int i = 1, j,ic, sum = 0;
	while (i <= N)
	{
		j = i;
		ic = 0;
		while (j)
		{
			ic += j % 10;
			j /= 10;
		}
		if (A <= ic && ic <= B)
			sum += i;
		i++;
	}
	cout << sum << endl;

}
