#include<bits/stdc++.h>
using namespace std;
int n;
long  long a[405];
long long f[405][405],s[405];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	    scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;++i)
	{
		int c=n-i+1;
		for(int j=1;j<=c;++j)
		{
			int l=j+i-1; 
			f[j][l]=f[j][j] + f[j+1][l];
			for(int k=j+1;k<=l;++k)
			  	f[j][l]=min(f[j][l],f[j][k]+f[k+1][l]);
			f[j][l]+=s[l]-s[j-1];
			//cout<<f[j][l]<<endl;
		} 
	}
	printf("%lld",f[1][n]);
	return 0;
}