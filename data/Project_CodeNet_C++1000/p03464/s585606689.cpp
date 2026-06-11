#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;
int a[100005];
long long leftt = 2, rightt = 2;

void compute(int cmd){
	// look for multiples of cmd in [left, right]
	long long lo = (leftt + cmd - 1) / cmd;
	long long hi = rightt / cmd;
	// now lo * cmd to (hi + 1) * cmd - 1 are possible
	leftt = lo * cmd;
	rightt = (hi + 1) * cmd - 1;
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = n; i >= 1; i--){
		compute(a[i]);
	//	printf("%lld %lld\n", leftt, rightt);
		if(leftt > rightt){
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld %lld\n", leftt, rightt);
}