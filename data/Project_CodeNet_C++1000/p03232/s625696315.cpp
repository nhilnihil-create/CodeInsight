#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ph push
#define ptc putchar
#define enter putchar('\n')
#define mod 1000000007
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

const int N = 1e5 + 10;
int n , a[N] , suminv[N] , presum[N] , sufsum[N] , dis[N] , ans;

int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n + 1;i++){
		suminv[i] = add(suminv[i-1] , qpow(i , mod - 2));
	}
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		presum[i] = add(presum[i-1] , a[i]);
	}
	for (int i = n;i >= 1;i--){
		sufsum[i] = add(sufsum[i + 1] , a[i]);
	}
	
	for (int dist = 0;dist <= n - 1;dist++){
		dis[dist] = presum[n - dist];
		if (dist){
			dis[dist] = add(dis[dist] , sufsum[dist + 1]);
		}
//		printf("[%d %d]\n",dist,dis[dist]);
	}
	
//	for (int i = 1;i <= n;i++) ans = add(ans , 1ll * add(suminv[i] - 1 , suminv[n - i + 1]) * a[i] % mod);
	for (int i = 0;i <= n - 1;i++) ans = add(ans , 1ll * qpow(i + 1 , mod - 2) % mod * dis[i] % mod);
	for (int i = 1;i <= n;i++) ans = 1ll * ans * i % mod;
	cout<<ans;
	return 0;
}

