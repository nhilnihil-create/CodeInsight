#include <iostream>
#include <cstdio>
#define ll unsigned long long
using namespace std;
ll a[1000006];
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read(), x = read();
	for (int i = 1; i <= n; ++ i)
		a[i] = read();
	for (int i = n; i; -- i)
		a[i] += a[i + 1];
	ll ans = -1;
	for (int k = 1; k <= n; ++ k){
		ll sum = 1LL * (k + n) * x + 5 * a[max(1, n - 2 * k + 1)];
		for (int i = max(1, n - 2 * k + 1) - 1, j = 7; i >= 1; i -= k, j += 2)
			sum += (a[max(1, i - k + 1)] - a[i + 1]) * j;
		if (ans == -1 || ans > sum)
			ans = sum;
	}
	cout << ans << endl;
}
