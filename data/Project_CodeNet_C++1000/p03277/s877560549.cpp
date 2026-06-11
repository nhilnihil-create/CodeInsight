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



const int N = 1e6+50;
int n, a[N], b[N];
int f[2*N], *cnt = f+N;

//求出中位数>=x的子区间个数
ll calc(int x) {
	REP(i,-n,n) cnt[i] = 0;
	ll ans = 0;
	int ret = 0, sum = 0, pos = 0;
	//ret维护0<=j<=i-1, s[j]<=s[i]的j的个数
	REP(i,1,n) {
		++cnt[sum], ++ret;
		if (a[i]>=x) ret += cnt[++sum];
		else ret -= cnt[sum--];
		ans += ret;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	REP(i,1,n) scanf("%d",a+i),b[i]=a[i];
	sort(b+1,b+1+n);
	int l=1,r=n,ans;
	ll m = (n+1ll)*n/2, pos = (m+1)/2;
	while (l<=r) {
		if (calc(b[mid])>=pos) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n", b[ans]);
}
