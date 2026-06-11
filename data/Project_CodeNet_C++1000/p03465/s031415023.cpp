/*
Atcoder AGC020C
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,a[2005],s=0;;
bitset<4000005> f[2];

signed main()
{
	cin>>n;
	for(int i=1;i<=n;cin>>a[i++]);
	for(int i=1;i<=n;i++)
		s += a[i];
	int o=0;
	f[o][0] = f[o][a[1]] = 1;
	for(int i=2;i<=n;i++)
	{
		o ^= 1;
		f[o] = f[o^1];
		f[o] |= f[o^1]<<a[i];
//		for(int j=0;j<=s;j++)cout<<f[o][j]<<' ';cout<<endl;
	}
	for(int j=(s+1)/2;j<=s;j++)
		if(f[o][j])
		{
			cout<<j<<endl;
			break;
		}
	
	return 0;
}