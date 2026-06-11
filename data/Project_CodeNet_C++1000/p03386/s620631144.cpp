#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;

int lst[Max];


int main()
{
	int a, b, k;
	cin >> a >> b >> k;
	map<int, int> ma;
	if (k >= b - a) for (int i = a;i <= b;i++)printf("%d\n", i);
	else
	{
		for (int i = a;i <= a + k - 1;i++)
		{
			printf("%d\n", i);
			ma[i]++;
		}
		for (int i = b - k+1;i <= b;i++)
		{
			if (ma[i] == 0)printf("%d\n", i);
		}
	}
		
}