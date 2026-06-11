#include<bits/stdc++.h>

using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef pair<LL, LL> pll;

#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fir first
#define sec second

#define fo0(i,a,b) for(int i=(a);i<(b);i++)
#define fo1(i,a,b) for(int i=(a);i<=(b);i++)
#define fd0(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define fd1(i,a,b) for(int i=(a);i>=(b);i--)
#define mset(a,b) memset(a,(b),sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

template<typename T> inline void in(T &x){x=0;int fl=1;char ch=getchar();while(ch<'0'||ch>'9')
{if(ch=='-')fl=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}x*=fl;}
template<typename T> void out(T x){if(x<0){putchar('-');x=-x;}if(x/10)out(x/10);putchar(x%10+'0');}
template<typename T> inline void outln(T x){out(x);putchar(10);}
template<typename T> inline void outsp(T x){out(x);putchar(' ');}
template<typename T> inline T gcd(T a, T b){T t;if(a>b){while(b){
t=b;b=a%b;a=t;}return a;}else{while(a){t=a;a=b%a;b=t;}return b;}}
template<typename T> inline T lcm(T a, T b){return a/gcd(a,b)*b;}

const int N = 500005;

int n, tim[N];
vector<int> a[N];

int main(){
	in(n);
	int t = sqrt(n*2);
	if(1ll * t * (t + 1) / 2 != n)	return puts("No"), 0;
	puts("Yes");
	int k = t + 1;
	outln(k);
	if(n == 1){
		printf("%d %d\n%d %d\n", 1, 1, 1, 1);
		return 0;
	}
	a[1].pb(1); a[1].pb(2);
	a[2].pb(2); a[2].pb(3);
	a[3].pb(1); a[3].pb(3);
	int now = 3;
	fo1(i, 4, k){
		fo1(j, now + 1, now + i - 1){
			a[i].pb(j);
			a[j - now].pb(j);
		}
		now += i - 1;
	}
	fo1(i, 1, k){
		outsp(t);
		fo1(j, 0, t-1)
			outsp(a[i][j]);
		putchar(10);
	}
	return 0;
}