#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
using namespace std;
template <typename _TP> inline void read(_TP &x){
	x = 0;int f = 1;char c = getchar();
	for(;c < '0' || '9' < c; c = getchar()) if(c == '-') f = -1;
	for(;'0' <= c && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;return;
}
template <typename _TP> inline void print(_TP x){
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
	return;
}
#define rg register
#define ll long long
#define r_2(a,b) read(a),read(b)
#define r_3(a,b,c) read(a),read(b),read(c)
#define print_n(a) print(a),puts("")
#define print_(a) print(a),putchar(' ')
const int inf = 2147483647;
const int maxn = 3e5 + 7;
const ll Mod = 998244353;
ll n,a,b,k,ans,lit;
ll fact[maxn],inv[maxn];
inline ll Pow(ll x,ll y){
	ll Ans = 1;
	while(y){
		if(y & 1) (Ans *= x) %= Mod;
		(x *= x) %= Mod;
		y >>= 1;
	}
	return Ans;
}
void fact_init(){
	fact[0] = fact[1] = 1;
	for(rg ll i = 2;i <= n; i++) fact[i] = fact[i - 1] * i % Mod;
	return;
}
void inv_init(){
	inv[n] = Pow(fact[n],Mod - 2);
	for(rg ll i = n - 1;i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % Mod;
	return;
}
inline ll C(ll x,ll y) {return fact[x] * inv[x - y] % Mod * inv[y] % Mod;}
int main()
{
	r_2(n,a);r_2(b,k);
	if(k == 0) {puts("1");return 0;}
	lit = min(n,k / a);
	fact_init();inv_init();
	for(rg ll i = 0;i <= lit; i++){
		if((k - i * a) % b) continue;
		ll num = (k - i * a) / b;
		if(num <= n) (ans += C(n,i) * C(n,num) % Mod) %= Mod;
	}
	print((ans + Mod) % Mod);
	return 0;
}