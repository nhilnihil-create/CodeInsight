#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 300300;
int res[MN];
int main() {
	ll n,a,b;
	scanf("%lld %lld %lld",&n,&b,&a);
	if(a*b < n) {printf("-1\n");return 0;}
	if(a+b > n+1) {printf("-1\n");return 0;}
	for(int i=0;i<b;i++) {
		res[i] = 1;n--;
	}
	for(int i=0;i<b;i++) {
		int h = min(n,a-res[i]);
		res[i] += h;n -= h;
	}
	int ct = 0;
	bool fs = true;
	for(int i=0;i<b;i++) {
		ct += res[i];
		for(int j=0;j<res[i];j++) {
			if(!fs) {printf(" ");}
			fs = false;
			printf("%d",ct-j);
		}
	}
	printf("\n");
}