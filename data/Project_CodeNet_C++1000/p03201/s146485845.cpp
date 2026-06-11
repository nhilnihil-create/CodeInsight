#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#ifdef sahdsg
#define DBG(...) printf(__VA_ARGS__)
#else
#define DBG(...) (void)0
#endif // sahdsg
#define REP(r,x,y) for(register int r=(x); r<y; r++)
using namespace std;
typedef long long LL;
inline void read(int&x) {
	x=0;char ch=getchar(); while(ch<'0') ch=getchar();
	while(ch>='0') x=x*10+ch-'0',ch=getchar();
}
map<int,int> a;
int main()
{
	int n; read(n);
	REP(i,0,n) {
		int t; read(t);
		if(a.count(t)==0) a[t]=0;
		a[t]++;
	}
	int ans=0;
	for(map<int,int>::reverse_iterator it=a.rbegin(); it!=a.rend(); it++) {
		int now=it->first;
		int k=now;
		k|=k>>1;
		k|=k>>2;
		k|=k>>4;
		k|=k>>8;
		k|=k>>16;
		k++;
		k-=now;
		DBG("%d %d %d\n", k, now, a[k]);
		if(k==now) ans+=a[k]/2,it->second%=2;
		else ans+=min(it->second,a[k]),a[k]-=min(it->second,a[k]);
	}
	printf("%d\n", ans);
}