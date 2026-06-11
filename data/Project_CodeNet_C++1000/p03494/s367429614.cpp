#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
#define PI acos(-1)

int main()
{
	int N;
	cin >> N;

	int* A = new int[N];

	int even = 0;
	int num = 0;
	int odd = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];

		if (A[i] % 2) 
		{
			odd = 1;
			break;
		}
	}

	if (odd == 0)
	{
		while (even == 0) {
			for (int i = 0; i < N; i++)
			{
				if (A[i] % 2 == 0)
				{
					A[i] /= 2;

					if (i == N - 1) 
					{
						num++;

					}
				}
				else
				{
					even = 1;
					break;
				}
			}
		}
	}


	cout << num;
}

