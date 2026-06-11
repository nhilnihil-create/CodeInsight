#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
int lst[Max], ls[Max];
int n;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &lst[i]);
	}
	sort(lst + 1, lst + 1 + n,greater<int>());
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 != 0)sum += lst[i];
		else sum -= lst[i];
	}
	cout << sum;
}