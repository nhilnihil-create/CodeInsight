//problem:
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e5+5;
int n,a[MAXN],aa[MAXN],s[MAXN];
struct BIT{
	ll c[MAXN];
	inline int lb(int x){return x&(-x);}
	void add(int p,ll v){for(;p<=n;p+=lb(p))c[p]+=v;}
	ll ask(int p){ll r=0;for(;p;p-=lb(p))r+=c[p];return r;}
	void clr(){memset(c,0,sizeof(c));}
	BIT(){}
}T;
bool check(int mid){
	for(int i=1;i<=n;++i)s[i]=(a[i]>mid?1:-1);
	vector<int>vec;vec.pb(0);
	for(int i=1;i<=n;++i)s[i]+=s[i-1],vec.pb(s[i]);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	T.clr();
	ll cnt=0;
	for(int i=0;i<=n;++i){
		int p=lob(vec.begin(),vec.end(),s[i])-vec.begin()+1;
		cnt+=T.ask(p);
		T.add(p,1);
	}//cnt:中位数>mid的区间数量
	return cnt<=((ll)n*(n+1)/2-1)/2;
}
int main() {
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),aa[i]=a[i];
	sort(aa+1,aa+n+1);
	check(8);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(aa[mid]))r=mid;
		else l=mid+1;
	}
	cout<<aa[l]<<endl;
	return 0;
}