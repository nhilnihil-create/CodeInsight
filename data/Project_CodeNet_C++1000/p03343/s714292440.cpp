#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int a[N], b[N], c[N];

int main(){
	int n, k, q, last, cnt, ans;
	scanf("%d %d %d",&n,&k,&q);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	ans = 2e9;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) b[j] = a[j];
		cnt = 0; last = 0;
		for (int j = 1; j <= n; j++){
			if (b[j] < a[i]){
				if (j - last - 1 >= k){
					sort(b + last + 1, b + j);
					for (int p = last + 1; p <= j - k; p++) c[++cnt] = b[p];
				}
				last = j;
			}
		}
		if (n - last >= k){
			sort(b + last + 1, b + n + 1);
			for (int p = last + 1; p <= n + 1 - k; p++) c[++cnt] = b[p];
		}
		if (cnt >= q){
			sort(c + 1, c + cnt + 1);
			ans = min(ans, c[q] - a[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}