#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



const int N = 1e5+10;
int n, a[N], b[N], d[N];
char s[N];

int main() {
	scanf("%d", &n);
	int c[2]{};
	REP(i,1,n) {
		scanf("%d%d",a+i,b+i);
		++c[a[i]+b[i]&1];
	}
	if (c[0]!=n&&c[1]!=n) return puts("-1"),0;
	printf("%d\n",31+!!c[0]);
	REP(i,0,30) printf("%d ", 1<<i);
	if (c[0]) printf("%d ", 1);
	hr;
	REP(i,1,n) {
		int x = a[i], y = b[i];
		if (c[0]) --x, s[31] = 'R';
		int f = 0;
		PER(i,0,30) {
			if (abs(x)<abs(y)) swap(x,y), f^=1;
			if (x>0) x-=1<<i,s[i]="RU"[f];
			else x+=1<<i,s[i]="LD"[f];
		}
		puts(s);
	}
}






