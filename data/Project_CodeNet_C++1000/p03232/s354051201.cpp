#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>


#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define debug(...) fprintf(stderr,__VA_ARGS__)

using namespace std;

inline char nc(){ static char buf[100000] , *p1,*p2; return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,100000,stdin),p1 == p2) ? EOF: *p1++;}
template<class T>inline void rd(T & x){ x = 0;char ch = nc();for(;!isdigit(ch);ch = nc()); for(;isdigit(ch);ch = nc()) x = x * 10 - 48 + ch;}

typedef long long ll;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int a[maxn],  inv[maxn];
void getinv(){
	inv[0] = inv[1] = 1;
	for(int i = 2;i < maxn;i++){
		inv[i] = mod - (ll)inv[mod % i] * (mod / i) % mod;
	}
}
int main(){
	int n;
	rd(n);
	for(int i = 1;i <= n;i++){ rd(a[i]); }
	getinv();
	int sum = 0,ans = 0;
	for(int i = 1;i <= n;i++) sum = (sum + inv[i]) % mod;
	for(int i = 1;i <= n;i++){
		ans = (ans + (ll)a[i] * sum % mod) % mod;
		sum = ((ll)sum - inv[n - i + 1] + mod) % mod;
		sum = (sum + inv[i + 1]) % mod;
	}
	for(int i = 2;i <= n;i++){
		ans = 1ll * ans * i % mod;
	}
	printf("%d\n",ans);
	return 0;
} 