#include <iostream>
#include <cmath>
using namespace std;
long long n, a, b, c;
int main() {
	cin>>n;
	while(n--) {
		cin>>a>>b;
		c = sqrt(a*b);
		if(a!=b && a*b==c*c) c--;
		cout<<(c*(c+1)>=a*b ? 2*c-2 : 2*c-1)<<endl;
	}
	return 0;
}