#include<bits/stdc++.h>
using namespace std;
int n,s;
bitset<4100000>b(1);
int main()
{
	int x;
	cin>>n;
	while (n--)
	{
		cin>>x;
		s += x;
		b |= b << x;
	}
	int ans = s;
	for (int i = s;i >= (s + 1) >> 1;--i)
		if (b[i])
			ans = i;
	cout<<ans;
}