#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=(1<<18)+10;
struct Data{
	ll mx,smx;
	void init(ll x){mx=x; smx=-1;}
	void update(Data x){
		if (x.mx>mx)
			smx=mx,mx=x.mx;
		else if (x.mx>smx)
			smx=x.mx;
		if (x.smx>smx)
			smx=x.smx;
	}
}info[N];
ll a[N];
int n;
ll ans;
bool in(int st,int x){return st>>x&1;}
int St(int x){return 1<<x;}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<(1<<n);++i) scanf("%lld",a+i),info[i].init(a[i]);
	for (int i=0;i<n;++i){
		for (int j=0;j<(1<<n);++j){
			if (in(j,i))
				info[j].update(info[j^St(i)]);
		}
	}
	ans=0;
	for (int i=1;i<(1<<n);++i){
		ans=max(ans,info[i].mx+info[i].smx);
		printf("%lld\n",ans);
	}
}
