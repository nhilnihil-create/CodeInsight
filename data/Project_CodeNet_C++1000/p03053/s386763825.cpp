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
#define REP(_i,_a,_n) for(int _i=_a;_i<=_n;++_i)
#define PER(_i,_a,_n) for(int _i=_n;_i>=_a;--_i)
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
#define DB(_a) ({REP(_i,1,n) cout<<_a[_i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head


const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
const int N = 1e3+10;
int n,m,d[N][N],vis[N][N];
char s[N][N];
queue<pii> q;

int main() {
	scanf("%d%d", &n, &m);
	REP(i,1,n) { 
		scanf("%s",s[i]+1);
		REP(j,1,m) if (s[i][j]=='#') { 
			vis[i][j] = 1;
			q.push(pii(i,j));
		}
	}
	int ans = 0;
	while (q.size()) {
		pii u(q.front()); q.pop();
		ans = d[u.x][u.y];
		REP(k,0,3) {
			int x=u.x+dx[k],y=u.y+dy[k];
			if (1<=x&&x<=n&&1<=y&&y<=m&&!vis[x][y]) {
				q.push(pii(x,y));
				vis[x][y] = 1;
				d[x][y] = d[u.x][u.y]+1;
			}
		}
	}
	printf("%d\n", ans);
}







