#include "bits/stdc++.h"
using namespace std;

//31
typedef long long ll;

//ll power(ll a , ll b) {
    //ll ans = 1;
	//while (b) {
		//if (b & 1) {
			//ans = ans  * a;
		//}
		//a = a * a;
		//b  /= 2;
	//}
	//return ans;
//}

int main() {
	int n;
	int k;
	scanf("%d%d",&n,&k);
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		double p = 1.0 / n;
		int x = i;
		while (x < k) {
			x *= 2;
			p /= 2;
		}
		ans += p;
	}
	printf("%.12f\n",ans);
}
