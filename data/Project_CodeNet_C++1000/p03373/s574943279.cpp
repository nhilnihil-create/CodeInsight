#include <iostream>
#include <bits/stdc++.h>
using namespace std;  

 int main(){
  	ios::sync_with_stdio(false);
    	cin.tie(0);  
	int A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y; 
        int ta=A; 
	int tb=B; 
	int tx=X; 
	int ty=Y; 
	if(X>Y){
		B=ta; 
		A=tb; 
		X=ty; 
		Y=tx; 
	}	
	if ((2*C)>(A+B)){
		cout<<A*X+B*Y; 
	}
	else if(2*C>B){ 
	       cout<<B*Y+(2*C-B)*X; 
	}else{ 
 		cout<<2*C*Y; 
	} 		

    
    return 0; 
}
