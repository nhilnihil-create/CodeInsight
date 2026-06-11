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
	ll n;
	cin >> n;
	ll a = 2, b = 1;
	for (int i = 1; i <= n ; i++)
	{
		ll t = b;
		b = a + b;
		a = t;
	}
	cout << a;

}