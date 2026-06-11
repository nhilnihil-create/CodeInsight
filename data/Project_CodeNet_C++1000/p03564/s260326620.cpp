#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = 1;
	for (int i = 1; i <= n; i++){
		if (ans <= k)
			ans <<= 1;
		else 
			ans += k;
	}
	printf("%d\n", ans);
	return 0;
}