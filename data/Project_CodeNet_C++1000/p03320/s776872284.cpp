#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 1500000; const double eps = 1e-9;
int s[N],len;
ll ans[N]; int size,dig[N];
//Vi res;
ll getdig(ll x) {ll res=0; while (x)res+=x%10,x/=10; return res;}
bool ok(int dig, ll x) {
	int cnt=0,pre=0; rep(i,1,len) if (s[i]==9)cnt=i; else break;
	per(i,len,cnt+1) pre=10*pre+s[i];
	ll mi=1; rep(i,1,cnt) mi*=10;
	
	
	rep(i,1,1) if (1LL*((pre+1)*mi-1)*getdig(1LL*((pre+1+i)*mi-1))>1LL*((pre+1+i)*mi-1)*(dig)) {
	//	if (dig==117 && x == 9999999999999) printf("i = %d\n",i);
		return 0;
	}
	return 1;
}
void dfs(int x) {
	if (len>15) return;
	if (!x) {
		++size; dig[size]=ans[size]=0;
		per(i,len,1) dig[size]+=s[i],ans[size]=10*ans[size]+s[i];
	//	if (ans[size]==9999999999999&&dig[size]==getdig(ans[size])) printf("OWO %d %d\n",dig[size],ok(dig[size],ans[size]));
		if (!ok(dig[size],ans[size])) {size--;}
		return;
	}
	if (x>27) {s[++len]=9; x-=9; dfs(x); return;}
	if (len>3&&s[len-3]!=9) return;
	rep(i,0,min(9,x)) {s[++len]=i; dfs(x-i); len--;}
}
int main() { //freopen("1.in","r",stdin);
//	cerr << ok(getdig(9999999999999),9999999999999);
 
	rep(i,1,140) {
		len=0;dfs(i);
	}
	sort(ans+1,ans+size+1);
	cerr << size <<endl;
//	cerr << ans[size] <<endl;
//	rep(i,1,size)printf("%lld,",ans[i]);
	int k; read(k);
	rep(i,1,k) printf("%lld\n",ans[i]);
	return 0;
}