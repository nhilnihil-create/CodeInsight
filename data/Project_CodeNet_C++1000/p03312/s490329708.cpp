#include <bits/stdc++.h>
using namespace std;

int a[200010];
long long sum[200010];

long long get_s(int l, int r){
	return sum[r] - sum[l - 1];
}

bool check(int a, int b, int c){
	return abs(get_s(a, b) - get_s(b + 1, c)) > abs(get_s(a, b + 1) - get_s(b + 2, c));
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = 3;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 2; i < n; i++){
		while (l < i - 1 && check(1, l, i)) l++;
		while (r < n - 1 && check(i + 1, r, n)) r++;
		long long minj = min(min(get_s(1, l), get_s(l + 1, i)), min(get_s(i + 1, r), get_s(r + 1, n)));
		long long maxj = max(max(get_s(1, l), get_s(l + 1, i)), max(get_s(i + 1, r), get_s(r + 1, n)));
		ans = min(ans, maxj - minj);
	}
	printf("%lld\n", ans);
	return 0;
}
