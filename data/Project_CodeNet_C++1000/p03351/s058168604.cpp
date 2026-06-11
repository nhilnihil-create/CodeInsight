#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int a,b,c,d,x=0,y=0,z=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	x=a-b;
	y=b-c;
	z=a-c;
	if(x<0) x*=-1;
	if(y<0) y*=-1;
	if(z<0) z*=-1;
	if(x<=d&&y<=d) printf("Yes\n");
	else if(z<=d) printf("Yes\n");
	else printf("No\n");
	return 0;
}
