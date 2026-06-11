#include<iostream>
#include <vector>

using namespace std;

int main()
{
	int Num;
	cin >> Num;
	
	int intCount = 0;



	for (int n = 1;n <= Num;n++)
	{
		int ans = 1;
		
		vector<int> x(n + 1);
		int num = n; // 素因数分解する変数num 

		for (int i = 2; i <= n; i++) {
			while (num % i == 0) { // 素数で割り切れなくなるまで割っていく
				x.at(i)++;
				num /= i;
			}
		}

		for (int i = 2; i <= n; i++)
		{
			ans *= x.at(i) + 1;
		}


		if (ans == 8&&n%2==1)
		{
			intCount++;
		}
		

	}

	cout << intCount << endl;
	
}