#include <stdio.h>

int main (){
    int v,e,n;
    scanf ("%d %d",&v , &e);
    if (e%v==0){
    	printf ("%d",v+e);
    	
	}else{
		printf ("%d",e-v);
	}
   return 0;
}