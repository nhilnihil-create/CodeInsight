#include<cstdio> 
#include<cstring> 
#include<algorithm> 
#define gc getchar() 
#define pc putchar 
#define int long long
inline int read() { 
	int x = 0,f = 1; 
	char c = gc; 
	while(c < '0' || c > '9') {if(c == '-')f = -1; char c = getchar();} 
	while(c <= '9' && c >= '0') x = x * 10 + c - '0',c = getchar(); 
	return x * f; 
} 
void print(long long  x) { 
	if(x < 0) { 
		pc('-'); 
		x = -x; 
	} 
	if(x >= 10) print(x / 10); 
	pc(x % 10 + '0'); 
} 
const int maxn = 500007; 
#define LL long long 
LL ans; 
LL sum[maxn],a[maxn]; 
main() { 
	LL n = read(), x = read(); 
	for(int i = 1;i <= n;++ i) a[i] = read(),sum[i] = sum[i - 1] + a[i],ans += 1ll * 5 * a[i] + 2ll * x; 
	for(int k = 1;k < n;++ k) { 
		LL tmp = k * x; 
		for(int nxj,j = n,cnt = 1;j > 0;j = nxj,cnt ++) {
			nxj = std::max(j - k,0ll); 
			LL s = sum[j] - sum[nxj]; 
			tmp += std::max(5ll,cnt * 2ll + 1ll) * s;  
			if(tmp > ans) break;  
		} 
		ans = std::min(ans,tmp); 
	} 
	print(ans + 1ll * n * x); pc('\n'); 
	return 0; 
} 