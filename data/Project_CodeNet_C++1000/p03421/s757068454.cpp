#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int ans[N];

int main(){
	int n, a, b, now, rec, pos, l, r;
	scanf("%d %d %d",&n,&a,&b);
	if (a > n || b > n || (n - 1) / a + 1 > b || a + b > n + 1){
		printf("-1\n");
		return 0;
	}
	now = n;
	for (int i = 1; i <= n; i += a){
		for (int j = min(n, i + a - 1); j >= i; j--) ans[now--] = j;
		b--;
	}
	for (int i = n - a; i >= 1 && b > 0; i -= a){
		rec = min(b, min(i, a) - 1);
		pos = max(i - a + 1, 1);
		l = ans[pos]; r = ans[i];
		for (int j = pos; j <= pos + rec - 1; j++) ans[j] = r - j + pos;
		for (int j = pos + rec; j <= i; j++) ans[j] = l + j - pos - rec;
		b -= rec;
	}
	for (int i = 1; i <= n; i++){
		printf("%d", ans[i]);
		if (i < n) printf(" ");
		else printf("\n");
	}
	return 0;
}