#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main()
{
	long N,K;
	cin >> N >> K;

	long num = N / K;

	long longCount = num*num*num;

	if (K % 2 == 1)
	{
		cout << longCount << endl;

		return 0;
	}
	else
	{
		long num2 = 0;

		for (int i = 0; i <= N; i++)
		{
			if (i % K == K / 2)
			{
				num2++;
			}
		}

		longCount= longCount+ num2 * num2 * num2;
		cout << longCount << endl;

		return 0;

	}





	cout << " "<< endl;

	return 0;


}

