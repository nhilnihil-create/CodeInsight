#include <bits/stdc++.h>
using namespace std;

const int N = 2005 * 2005;
bitset<N> d;
int n;
int sum;
int a[N];

int main() 
{
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}	
	int req = (sum + 1)/2;
	d[0] = 1;
	for(int i=1; i<=n; i++)
	{
		d |= (d << a[i]);
	}
	for(int i=req; i<N; i++) 
	{
		if(d[i])
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
