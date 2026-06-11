#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	long long n,s,t=1,ans=0;
	int i;
	scanf("%lld",&n);
	scanf("%lld",&s);
	a[0]=s;
	for (i=1;i<n;i++)
	  scanf("%lld",&a[i]);
	i=1;
	long long k=0;
	ans=1;
	while (i<n)
	{
	  if ((s^a[i])==s+a[i])
	  {
	  	s^=a[i];
	  	i++;
	  	t++;
	  	ans+=t;
	  	k=0;
	  } else
	  {
	  	s-=a[i-t];
	  	t--;
	  	k=1;
	  }
	    
    }
    printf("%lld",ans);
}