#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[233333];
int n;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] -= i;
	sort(a + 1, a + 1 + n);
	ll Mid = 0, ans = 0;
	if(n % 2 == 0) Mid = (a[n / 2] + a[n / 2 + 1]) / 2;
	else Mid = a[n / 2 + 1];
	for(int i = 1; i <= n; i++) ans += abs(a[i] - Mid);
	printf("%lld\n", ans);
	return 0;
}