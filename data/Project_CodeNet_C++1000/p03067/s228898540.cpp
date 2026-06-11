#include<cstdio>
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	if((a>=c&&b<=c)||(a<=c&&b>=c))puts("Yes");
	else puts("No");
}