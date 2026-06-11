#include<cstdio>
#include<algorithm>
int t[35],k;
struct r{
	int x,y;
}a[1050];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++)if (((a[i].x+a[i].y)&1)!=((a[1].x+a[1].y)&1))return printf("-1\n"),0;
	int m=31;
	if (!((a[1].x+a[1].y)&1))m++;
	printf("%d\n",m);
	for (int i=30;i>=0;i--)printf("%d ",t[k++]=(1<<i));
	if (m==32)printf("1");
	printf("\n");
	for (int i=1;i<=n;i++){
		if (m==32)a[i].x--;
		for (int j=0;j<=30;j++){
			if (abs(a[i].x)>abs(a[i].y))
				a[i].x<0?(a[i].x+=t[j],printf("L")):(a[i].x-=t[j],printf("R"));
			else a[i].y<0?(a[i].y+=t[j],printf("D")):(a[i].y-=t[j],printf("U"));
		}
		if (m==32)printf("R");
		putchar('\n');
	}
} 