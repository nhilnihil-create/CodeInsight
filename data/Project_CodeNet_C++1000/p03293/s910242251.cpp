#include<stdio.h>
#include<string.h>
int main()
{
	char a[105],b[105], tmp, tmp2,tmp3;
	scanf(" %s",a);
	scanf(" %s",b);
	int j, i,l;
	l=strlen(a);
	for(j=0;j<l;j++){
		if(0==strcmp(a,b)){ printf("Yes\n"); return 0; }
	tmp=a[l-1];
	tmp2=a[0];
	tmp3=a[1];
	for(i=1;i<l;i++) { a[i]=tmp2; tmp2=tmp3;
	tmp3=a[i+1]; }
	a[0]=tmp;
	
	
}
printf("No\n");
}