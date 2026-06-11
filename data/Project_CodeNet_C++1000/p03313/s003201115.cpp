#include <bits/stdc++.h>
using namespace std;

int a[1 << 20], ans[1 << 20], maxx[1 << 20];

int main(){
	int k, n;
	scanf("%d",&k);
	n = (1 << k);
	for (int i = 0; i < n; i++) scanf("%d",&a[i]);
	memset(ans, 0, sizeof(ans));
	memset(maxx, 0, sizeof(maxx));
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j = (j + 1) | i){
			ans[j] = max(ans[j], a[i] + maxx[j]);
			maxx[j] = max(maxx[j], a[i]);
		}
	}
	for (int i = 1; i < n; i++) ans[i] = max(ans[i], ans[i - 1]);
	for (int i = 1; i < n; i++) printf("%d\n", ans[i]);
	return 0;
}