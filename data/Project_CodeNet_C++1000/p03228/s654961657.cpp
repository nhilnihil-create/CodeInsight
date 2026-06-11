#include <iostream>
using namespace std;

int main() {
	int a,b,k;cin >>a>>b>>k;
	for(int i=0;i<k/2;++i){
		if(a%2!=0)--a;
		a/=2;
		b += a;
		if(b%2!=0)--b;
		b/=2;
		a += b;
	}
	if(k%2!=0){
		if(a%2!=0)--a;
		a/=2;
		b += a;
	}
	cout << a << " " << b << endl;
	return 0;
}