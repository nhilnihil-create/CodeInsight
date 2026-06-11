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



const int N = 1e6+10;
int n, a[N];
vector<pii> s;

int chk(int x) {
	s.clear();
	s.pb(pii(1,a[1]));
	REP(i,2,n) {
		if (a[i]>a[i-1]) { 
			s.pb(pii(1,a[i]-a[i-1]));
			continue;
		}
		int len = a[i-1]-a[i];
		while (len) {
			if (s.back().y<=len) len-=s.back().y,s.pop_back();
			else {
				s.back().y -= len;
				if (!s.back().y) s.pop_back();
				break;
			}
		}
		while (s.size()>1) {
			pii u = s.back(), v = s[s.size()-2];
			if (u.x==v.x) {
				s.pop_back();
				s.back().y += u.y;
			}
			else break;
		}
		if (s.back().x==x) {
			if (s.size()==1) return 0;
			else {
				pii u = s.back();
				s.pop_back();
				int t = s.back().x;
				if (!--s.back().y) s.pop_back();
				s.pb(pii(t+1,1));
				s.pb(pii(1,u.y));
			}
		}
		else {
			int t = s.back().x;
			if (!--s.back().y) s.pop_back();
			s.pb(pii(t+1,1));
		}
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	REP(i,1,n) scanf("%d",a+i);
	int l=1,r=n,ans;
	while (l<=r) {
		if (chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n", ans);
}
