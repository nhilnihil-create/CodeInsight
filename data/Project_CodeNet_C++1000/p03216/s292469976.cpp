#include <bits/stdc++.h>

using namespace std;

#define N 1000000

char str[N + 2];
long long sum_d[N + 2];
long long sum_m[N + 2];
long long sum_dm[N + 2];

long long query_d(int l, int r){
	return sum_d[r] - sum_d[l - 1];
}

long long query_m(int l, int r){
	return sum_m[r] - sum_m[l - 1];
}

int main(){
	int n, q, k, i;
	long long ans;

	scanf("%d", &n);
	scanf(" %s", str + 1);

	for (i = 1; i <= n; i++){
		sum_d[i] = sum_d[i - 1] + (str[i] == 'D');
		sum_m[i] = sum_m[i - 1] + (str[i] == 'M');
		sum_dm[i] = sum_dm[i - 1] + (str[i] == 'M' ? sum_d[i] : 0);
	}

	scanf("%d", &q);

	while (q--){
		scanf("%d", &k);
		ans = 0;

		for (i = 1; i <= n; i++){
			if (i <= k){
				if (str[i] == 'C'){
					ans += sum_dm[i];
				}
			}
			else{
				if (str[i] == 'C'){
					ans += sum_dm[i] - sum_dm[i - k] - query_d(1, i - k) * query_m(i - k + 1, i - 1);
				}
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}