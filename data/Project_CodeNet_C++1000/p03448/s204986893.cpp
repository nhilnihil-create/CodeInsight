#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
int ls1[Max], ls2[Max];
int n;


int main()
{
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	ll sum = 0;
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			for (int k = 0; k <= c; k++)
			{
				if (i * 500 + j * 100 + 50 * k == x)
					sum++;
			}
		}
	}
	cout << sum;
}