#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

long long a[N];

int main(){
	int n, now;
	long long x, ans, sum;
	scanf("%d %lld",&n,&x);
	a[0] = 0;
	ans = 1e18;
	for (int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		a[i] += a[i - 1];
	}
	for (int k = 1; k <= n; k++){
		sum = 0; now = 3;
		for (int i = n; i >= 1; i -= k){
			sum += (a[i] - a[max(0, i - k)]) * max(now, 5);
			now += 2;
			if (sum >= ans) break;
		}
		ans = min(ans, sum + x * (n + k));
	}
	printf("%lld\n",ans);
	return 0;
}