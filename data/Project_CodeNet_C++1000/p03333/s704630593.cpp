#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, die[101000], pl, pr, now;
struct L{
	int l, r, id;
}a[101000], sl[101000], sr[101000];

bool cmpl(L a,L b){
	return a.l>b.l;
}
bool cmpr(L a,L b){
	return a.r<b.r;
}

int gao(L *s,int &pos){
	for (;die[s[pos].id];) ++pos;
	return s[pos].id;
}

ll cal(){
	ll res=0, p=0;
	memset(die,0,sizeof die); pl=pr=1;
	for (int i=1;i<=n;++i){
		int id;
		id= now? gao(sl,pl): gao(sr,pr);
		if (p>a[id].r){
			res+=p-a[id].r; p=a[id].r;
		}
		if (p<a[id].l){
			res+=a[id].l-p; p=a[id].l;
		}
		die[id]=1; now^=1;
	}
	return res+abs(p);
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].id=i;
		sl[i]=sr[i]=a[i];
	}
	sort(sl+1,sl+n+1,cmpl);
	sort(sr+1,sr+n+1,cmpr);

	ll ans=0;
	for (int org=0;org<=1;++org){
		now=org;
		ans=max(ans,cal());
	}
	cout<<ans<<endl;
}