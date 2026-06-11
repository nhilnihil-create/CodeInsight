#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define gc getchar
#define pc putchar
#define fi first
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
#define rank __RAnK
inline ll read(){
	register ll x=0,f=1;register char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
#define rd read
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int maxn = 1e5+233;
vector<pair<int,int> > ans;
int d[maxn],w[maxn],a[maxn];
int del,n;
bool cmp(int x,int y){
	return d[x] < d[y];
}
int query(int l,int r,int need){
	int pos = -1;
	while(l<=r){
		int mid =(l+r)>>1;
		if(d[a[mid]] - del < need) l = mid + 1; else
		if(d[a[mid]] - del > need) r = mid - 1; else
		return a[mid];
	}
	return -1;
}
signed main(){
	n = rd();
	Rep(i,1,n) d[i] = rd();
	Rep(i,1,n) w[i] = 1;
	Rep(i,1,n) a[i] = i;
	sort(a+1,a+1+n,cmp);//从小到大排序 
	del = 0;
	Dep(i,n,2){
		/*当前是a[i] - del，权重为w[i]
		移动一步
		对于所有(n-w[i])个点，都要减少1*/
		ll need = d[a[i]] - del - (n - w[a[i]]) + w[a[i]]; 
		int pos = query(1,i-1,need);//找到标号
		if(pos == -1){
			puts("-1");
			return 0;
		}
		del += w[a[i]];
		w[pos] += w[a[i]];
		ans . push_back(pii(a[i],pos));
	}
	if(d[a[1]] != del){
		puts("-1");
		return 0;
	}
	for(auto i:ans){
		printf("%lld %lld\n",i.fi,i.se);
	}
	return 0;
}
