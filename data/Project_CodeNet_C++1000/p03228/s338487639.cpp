#include<iostream>
using namespace std;
int main(){
	int a,b,k,i;
	cin>>a>>b>>k;
	for(i=0;i<k;i++){
		if(i%2==1){
			b/=2;
			a+=b;
		}else{
			a/=2;
			b+=a;
		}
	}
	cout<<a<<" "<<b;
	return 0;
}