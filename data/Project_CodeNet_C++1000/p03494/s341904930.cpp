#include <iostream>

using namespace std;

int main(){

	int n;
	cin>>n;
	int a;
	int s=1000000000;
	int c=0;
	for(int i=0;i<n;i++){
	
		cin>>a;
		while(a%2==0){
		
			a/=2;
			c++;
		}
		if(c==0){
		
			cout<<0;
			return 0;
		}
		if(c<s){
		
			s=c;
		}
		c=0;
	}
	cout<<s<<'\n';
	return 0;
}
