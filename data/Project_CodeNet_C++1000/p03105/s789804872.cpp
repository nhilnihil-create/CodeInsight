#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B,C;
  	cin>>A>>B>>C;
  	int kotae;
  	int sound = B;

	for(int i=0;i<C;i++){

        if(sound>=A){
          kotae++;
          }
      	else{
      		break;
        }
      
    	sound -= A ;
                    
    }
      cout<<kotae<<endl;
          
}
  