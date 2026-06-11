#include <bits/stdc++.h>
using namespace std;
int n,x,s;
bitset<2000007>f;
int main()
{
	cin>>n;
	f[0]=1;
	for(register int i=1;i<=n;i++)
	{
		cin>>x;
		f|=f<<x;
		s+=x;
	}
	for(register int i=(s+1)/2;i<=s;i++)
		if(f[i]) 
		{
			cout<<i<<endl;
			break;
		}
	return 0;
}