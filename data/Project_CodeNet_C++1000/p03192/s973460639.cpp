#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<4;i++) {
		if(n%10 == 2) ans++;
		n /= 10;
	}
	printf("%d\n",ans);
	return 0;
}