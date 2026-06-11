#include <iostream>
#include <cmath>
using namespace std;
long long x,y,maks;
int main() {
cin>>x>>y;
for(long long i=1;i<100;i++) {
	maks=pow(2,i-1)*x;
	if(maks>y) {
		cout<<i-1<<endl;
		break;
	}
}
}