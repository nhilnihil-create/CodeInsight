#include <iostream>
#include <stdio.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


int main()
{
    int x,y,z;
    scanf("%d",&x);
    scanf("%d",&y);
    
    if(x%y==0){
    	printf("-1");
    }
    else{
    	
    
    rep(i,y){
    	if((x*i)%y==0){
    		;
    	}else{
    		z=x*i;
    		break;
    	}
    }
    printf("%d",z);
    }
    
}