#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ph push
#define ptc putchar
#define enter putchar('\n')
#define mod 998244353
using namespace std;
typedef pair<int,int> pii;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef long long lnt;
inline int read(){
	int x = 0;char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = (x << 1) + (x << 3) + c - '0' , c = getchar();
	return x;
}
inline void write(int x){
	if (!x){
       ptc('0');
       return;
	}
	int dg[20] , len = 0;
	while (x) dg[len++] = x % 10 , x /= 10;
	while (len--) ptc(dg[len]+'0');
}
inline void writeln(int x){
	write(x);
	ptc('\n');
}
inline int add(int x,int y){
	x += y;if (x >= mod) x -= mod;
	return x;
}
inline int sub(int x,int y){
	x -= y;if (x < 0) x += mod;
	return x;
}
inline int qpow(int x,int y){
	int res = 1;
	while (y){
		if (y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;y >>= 1;
	}
	return res;
}
lnt a , b , c , d , pd , pa;
int T;
int main(){
	cin >> T;
	while (T--){
		cin >> a >> b >> c >> d;
		if (a < b || d < b){
			puts("No");
			continue;
		}
		a %= b;
		d %= b;
		d = __gcd(d , b);
		ll smallest = ((c + 1 - a + d - 1) / d);
		
//		printf("%lld\n",smallest);
		if (smallest * d + a < b){
			puts("No");
			continue;
		}
		puts("Yes");
	}
	
	return 0;
}