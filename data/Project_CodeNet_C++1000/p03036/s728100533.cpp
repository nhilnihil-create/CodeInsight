#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll r, d, x, temp;
	cin >> r >> d >> x;
	temp = x;
	for (int i = 0; i < 10; i++)
	{
		cout << r * temp - d << endl;
		temp = r * temp - d;
	}
	return 0;
}