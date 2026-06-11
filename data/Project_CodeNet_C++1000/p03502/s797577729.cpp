#include <iostream>
using namespace std;

int main(){
	int n,sum=0;
  	cin>>n;
  	
  	for(int i=n;i>0;i/=10){
    	sum+=i%10;
    }
  
  	if(n%sum)
      cout<<"No";
  	else
      cout<<"Yes";
  	
  	
}