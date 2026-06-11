#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, a[200005];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] >= i){
			printf("-1\n");
			return 0;
		}
		if(i > 1 && a[i] >= a[i - 1] + 2){
			printf("-1\n");
			return 0;
		}
	}
	
	long long ans = 0;
	
	for(int i = n; i > 0; i--){
		ans += a[i];
		while(i > 1 && a[i - 1] == a[i] - 1){
			i--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}