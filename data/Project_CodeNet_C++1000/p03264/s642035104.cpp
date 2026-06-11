#include <iostream>
using namespace std;

int batas, even, odd, sementara;


int main(){
	cin>>batas;
	if(batas%2==1){
		sementara=batas-1;
		sementara/=2;
		even=sementara;
		odd=batas-sementara;
	}else{
		odd=batas-batas/2;
		even=batas/2;
	}
	cout<<even*odd<<endl;
}