#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
int lst[Max], ls[Max];
int n;

bool check(int n)
{
	int lst[Max];
	int i = 0;
	while (n > 0)
	{
		lst[++i] = n % 10;
		n /= 10;
	}
	int f = 0;
	for (int j = 1; j <= i / 2; j++)
	{
		if (lst[j] != lst[i - j + 1]) return false;
	}
	return true;
}

int main()
{
	int a, b;
	cin >> a >> b;
	int sum = 0;
	for (int i = a; i <= b; i++)
	{
		if (check(i))
		{
			sum++;
		}
	}
	cout << sum;

}