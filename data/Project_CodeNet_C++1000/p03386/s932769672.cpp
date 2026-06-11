#include<iostream>
using namespace std;

typedef long long int llint;

int main(){
	llint A,B,K;
	cin >> A >> B >> K;
	if(B-A+1>=2*K){
		for(int i=1;i<=K;i++){
			cout << (A+(i-1)) << endl;
		}
		for(int i=K;i>=1;i--){
			cout << (B-(i-1)) << endl;
		}
	}else{
		for(llint i=A;i<=B;i++){
			cout << i << endl;
		}
	}
	return 0;
}
