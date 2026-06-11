#include <cstdio>
int n,ans;
int main()
{
	scanf("%d",&n);
  	while(n)
    {
		if(n%10==2) ans++;
      	n/=10;
    }
  	printf("%d",ans);
  	return 0;
}