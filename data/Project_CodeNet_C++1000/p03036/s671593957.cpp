#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;

int main()
{
	ll r; ll d; ll x;
	cin >> r >> d >> x;
	ll ans = r * x - d;
	cout << ans << endl;
	for (int i = 2; i <= 10; i++)
	{
		ans = ans * r - d;
		cout << ans << endl;
	}
	return 0;
}