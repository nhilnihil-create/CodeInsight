#include <bits/stdc++.h>
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	if (a+b>=c-1){
		printf("%d\n",b+c);
		return 0;
	}
	printf("%d\n",a+b+1+b);
}