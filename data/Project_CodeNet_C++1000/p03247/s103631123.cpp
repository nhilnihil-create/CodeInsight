#include<stdio.h>
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<set>
#include<deque>
#include<queue>
#include<vector>
//#include<unordered_map>
#include<map>
#include<stack>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define Pii pair<ll,int>
#define m_p make_pair
#define l_b lower_bound
#define u_b upper_bound
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e3 + 11;
const int maxm = 600 + 11;
const int mod = 1e9 + 7;
const double eps = 1e-5;
inline ll rd() { ll x = 0, f = 1; char ch = getchar(); while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }return x * f; }
inline ll qpow(ll a, ll b, ll p) { ll res = 1; while (b) { if (b & 1) { res *= a; res %= p; }b >>= 1; a = a * a%p; }return res; }
inline ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a%b); }
//iterator
//head
//priority_queue
ll X[maxn],Y[maxn];
ll d[maxn]; 
int len=0;
void Print(ll x,ll y){
	for(int i=1;i<=len;i++){
		if(abs(x)>abs(y)){
			if(x>0) x-=d[i],printf("R");
			else x+=d[i],printf("L");
		}
		else{
			if(y>0) y-=d[i],printf("U");
			else y+=d[i],printf("D");
		}
	}
	puts("");
}
void run(){
	int n=rd();
	int z=0,f=0;
	for(int i=1;i<=n;i++){
		X[i]=rd(),Y[i]=rd();
		if(abs(X[i]+Y[i])%2) z=1;
		else f=1;  
	}
	if(z&&f) {
		puts("-1");
		return;
	}
	
	for(int i=30;i>=0;i--){
		d[++len]=(1ll<<i);
	}
	if(f) d[++len]=1;
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		if(i==len) printf("%lld\n",d[len]);
		else printf("%lld ",d[i]);
	} 
	for(int i=1;i<=n;i++){
		Print(X[i],Y[i]);
	}
}
int main() {
	run();
}