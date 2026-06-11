#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
#define PI acos(-1)

int main()
{
	int A, B, C, X;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> X;

	int num = 0;

	for (int a = 0; a <= A; a++)
	{
		for (int b = 0; b <= B; b++)
		{
			for (int c = 0; c <= C; c++)
			{
				if ((500 * a + 100 * b + 50 * c) == X) 
				{
					num++;
				}

				if ((500 * a + 100 * b + 50 * c) > X)
				{
				break;
				}
				
			}
		}
	}

	cout << num;
}

