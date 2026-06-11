#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int mn = 10000;
	for(int i=1;i<=n/2;i++)
	{
		int a = i,b = n - i;
		int c=0,d=0;
		while(a > 0)
		{
			c += a % 10;
			a /= 10;
		}
		while(b > 0)
		{
			d += b % 10;
			b /= 10;
		}
		mn = min(mn,c+d);
	}
    cout << mn << endl;
	return 0;
}
