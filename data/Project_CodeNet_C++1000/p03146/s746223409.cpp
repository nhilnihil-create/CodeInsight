#include <iostream>

using namespace std;

int main(){

	int n;
	cin>>n;
	if(n==4||n==2||n==1){
	
		cout<<4;
		return 0;
	}
	int j=1;
	while(n!=4){
	
		if(n%2==0){
		
			n/=2;
		}
		else{
		
			n*=3;
			n++;
		}
		j++;
	}

	cout<<j+3;
}
