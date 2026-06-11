#include <stdio.h>
int main (){
int x,y;
scanf("%d %d",&x ,&y);

if(y%x==0){
	printf("%d\n",x+y);
	
}	else{
	printf("%d\n",y-x);
}
	
	
	return 0;
	
}