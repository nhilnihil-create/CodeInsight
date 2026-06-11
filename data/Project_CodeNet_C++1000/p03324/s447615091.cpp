#include<iostream>
using namespace std;

int main(){
	int d,n;
	cin>>d>>n;
	int fir = 1;
	for(int i=0; i<d; i++) fir*=100;
	if(n<100) cout<<fir*n;
	else cout<<fir*101;
}