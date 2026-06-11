#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int func(int num){
	int k;	
	if(num==1||num==0) return 0;
	if(num==2) return 1;
      for(k=2;k<=sqrt(num)+1;k++){
			if(num%k==0) return 0;	     	 
		}
    return 1;
   } 
   
int main(){
	int q,i,j,l,r;   
	int c[100001],js[100001];
	js[1]=0;
	for(i=2;i<=100000;i++){
		if (func(i)==1&func((i+1)/2)) js[i]=js[i-1]+1;
		else js[i]=js[i-1];
    	}
   scanf("%d",&q);
	for(i=1;i<=q;i++){
	     scanf("%d %d",&l,&r);  
	      c[i]=js[r]-js[l-1];	    	
		 }	       
    for(i=1;i<=q;i++){
		printf("%d\n",c[i]);
     	} 
	return 0;
    } 