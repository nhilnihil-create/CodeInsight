#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
char lst[Max][Max];
int ls[Max][Max];

int main()
{
	ll n, k;
	cin >> n >> k;
	ll sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum += min(sum, k);
	}
	cout << sum;
}