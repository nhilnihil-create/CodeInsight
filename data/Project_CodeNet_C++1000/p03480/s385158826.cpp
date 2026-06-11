#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int n=a.size(),f=1,w=n/2+n%2;
	for(int i=0;i<n;i++) if(a[i]=='0')
	{
		f--;
		break;
	}
	if(f) printf("%d\n",n);
	else
	{
		for(;w<n;w++)
			if(a[w]!=a[w-1]||a[w]!=a[n-w-1])
				break;
		printf("%d",w);
	}
	return 0;
}