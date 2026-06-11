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
typedef unsigned long long ull;
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

const int N = 18;
const ull base = 28;

ull mi[N];
char s[N];
int n , cnt[26];
lnt answer;
map<ull,ll> exi;


void dfs(int cur,ull sb,ull sr){
	if (cur == (n << 1 | 1) ){
//		printf("%llu %llu\n",sb,sr);
		exi[(sb << 30) + sr]++;
		return; 
	}
	dfs(cur + 1 , sb * base + s[cur] - 'a' + 1 , sr);
	dfs(cur + 1 , sb , sr * base + s[cur] - 'a' + 1);
}

int a[N] , b[N] , acnt , bcnt;

void dfs(int cur){
	if (cur == n + 1){
		ull sb = 0 , sr = 0;
		for (int i = bcnt;i >= 1;i--) sr = sr * base + b[i];
		for (int i = acnt;i >= 1;i--) sb = sb * base + a[i];
		
//		for (int i = 1;i <= acnt;i++) printf("%c",a[i]+'a'-1);enter;
//		for (int i = 1;i <= bcnt;i++) printf("%c",b[i]+'a'-1);enter;
//		printf("  %llu %llu\n",sb,sr);
		if (exi.count((sb << 30) + sr))answer += exi[(sb << 30) + sr];
		return;
	}
	a[++acnt] = s[cur] - 'a' + 1;dfs(cur + 1);--acnt; 
	b[++bcnt] = s[cur] - 'a' + 1;dfs(cur + 1);--bcnt; 
	
}
int main(){
	scanf("%d",&n);
	scanf("%s",s + 1);
	mi[0] = 1;for (int i = 1;i <= 2 * n;i++) mi[i] = base * mi[i-1];
	
	for (int i = 1;i <= 2 * n;i++){
		cnt[s[i]-'a']++;
	}
	for (int i = 0;i < 26;i++){
		if (cnt[i] & 1) return puts("0") , 0;
	}
	
	dfs(n + 1 , 0 , 0);
	dfs(1);
	
	cout<<answer<<endl;
	return 0;
}