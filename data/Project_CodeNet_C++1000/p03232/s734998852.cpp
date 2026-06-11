#include <iostream>
#include <cstdio>
#define mod 1000000007
using namespace std;
int a[1000006], s[1000006];
int fpw(int x, int y){
	int ans = 1;
	for (int i = 1; i <= y; i <<= 1, x = 1LL * x * x % mod)
		if (y & i)
			ans = 1LL * ans * x % mod;
	return ans;
}
int add(int x, int y){
	x += y;
	if (x >= mod)
		return x - mod;
	return x;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		s[i] = add(s[i - 1], fpw(i + 1, mod - 2));
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
		ans = (ans + 1LL * add(s[i - 1], s[n - i] + 1) * a[i] % mod) % mod;
	for (int i = 1; i <= n; ++ i)
		ans = 1LL * ans * i % mod;
	cout << ans << endl;
}
