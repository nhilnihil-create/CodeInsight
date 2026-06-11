#include <stdio.h>

int main (){
	int a,b;
	
	scanf ("%d %d",&a,&b);
	
	if (b%a==0){
		printf ("%d",a+b);
	}
	else if (a==1 && b==1){
		printf ("1");
	}
	else {
		printf ("%d",b-a);
	}
	return 0;
}