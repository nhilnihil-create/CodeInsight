#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
	int a,b,k;
	cin >> a >> b >> k;
	for(int i = 0;i<k;i++)
	{
		if(i&1)
		{
			a+=b/2;
			b/=2;
		}
		else
		{
			b += a/2;
			a /= 2;
		}
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}