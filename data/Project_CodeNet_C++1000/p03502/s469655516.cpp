#include<bits/stdc++.h>
using namespace std;

int main(){
	int X,k,waru=1,sum=0;
  	cin>>X;
  	k=X;
  	
  	for(int j=0;k>10;j++){
  		for(int i=0;i<9-j;i++){
      	waru=waru*10;
    	}
      	sum += k/waru;
      	k = k%waru;
       
      	waru=1;
      	
 
    }
  	int FX = sum+k;
  
  	if(X%FX==0){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
}
      	
      	