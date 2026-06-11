#include <iostream>
using namespace std;

int main(){
	int n,x,d,a;
  	cin>>n>>d>>x;
  	for(int i=0;i<n;i++){
    	cin>>a;
      	for(int i=1;i<=d;i+=a){
        	x+=1;
        }
    }
  cout<<x;
  	
}