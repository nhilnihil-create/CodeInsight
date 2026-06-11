#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[11000000],s[11000000],b[11000000];
int main()
{
	cin>>n;
	n=(long long)pow(2,n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)
	  for(int j=i;j<=n;j=(j+1)|i)
	  {
	  	s[j]=max(s[j],a[i]+b[j]);
	  	b[j]=max(b[j],a[i]);
	  }
	for(int i=1;i<n;i++)s[i]=max(s[i],s[i-1]);
	for(int i=1;i<n;i++)printf("%lld\n",s[i]);
	return 0;
} 