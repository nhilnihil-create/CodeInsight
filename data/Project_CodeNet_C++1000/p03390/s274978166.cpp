#include <iostream>
#include <cmath>
using namespace std;
long long n, a, b, c, ans;
int main() {
	cin>>n;
	while(n--) {
		cin>>a>>b;
		if(a==b) ans = 2*a-2;
		else {
			c = sqrt(a*b);
			if(c*c==a*b) c--;
			ans = (c*(c+1)>=a*b ? 2*c-2 : 2*c-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}