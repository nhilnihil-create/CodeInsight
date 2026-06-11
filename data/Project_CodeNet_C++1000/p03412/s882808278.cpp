#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int bit[30][N], a[N], b[N], dx[N];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int k = 0; k < 28; k++)
		for (int i = 1; i <= n; i++)
			bit[k][i] = b[i] & ((1 << (k + 1)) - 1);
	for (int i = 0; i < 28; i++)
		sort(bit[i] + 1, bit[i] + n + 1);
	int ans = 0;
	for (int k = 1; k <= 28; k++)
		for (int i = 1; i <= n; i++) {
			dx[i] ^= (1 << (k - 1)) & a[i];
			int x = lower_bound(bit[k - 1] + 1, bit[k - 1] + n + 1, (1 << k) - dx[i]) - bit[k - 1];
			ans ^= ((n - x + 1) % 2) << k;
		}
	int a0, a1, b1, b0;
	for (int k = 0; k <= 28; k++) {
		a0 = a1 = b0 = b1 = 0;
		for (int i = 1; i <= n; i++)
			if ((1 << k) & a[i])
				a1++; 
			else 
				a0++;
		for (int i = 1; i <= n; i++)
			if ((1 << k) & b[i])
				b1++;
			else
				b0++;
		ans ^= (((1ll * a1 * b0 % 2 + 1ll * a0 * b1 % 2) % 2) << k);
	}
	printf("%d", ans);
}