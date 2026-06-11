#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fst first
#define snd second

const int MAXN=2e5+15;
int n;
ll a[MAXN],sp[MAXN];
ll sum(int i,int j){return sp[j]-sp[i-1];}
ll get(int i,int j,int k) {
	return abs(sum(i,j)-sum(j+1,k));
}
ii get(int i,int j) {
	int l=i,r=j-1;
	while(l<=r) {
		int m1=l+(r-l)/3;
		int m2=r-(r-l)/3;
		if(get(i,m1,j)<get(i,m2,j))r=m2-1;
		else l=m1+1;
	}
	// cout<<i<<" "<<j<<" : r: "<<r<<endl;
	ii res={sum(i,r),sum(r+1,j)};
	if(res.fst>res.snd)swap(res.fst,res.snd);
	// cout<<i<<" "<<j<<" : "<<res.fst<<" "<<res.snd<<endl;
	return res;
}
ll get(ii a,ii b){
	return max(a.snd,b.snd)-min(a.fst,b.fst);
}
int main() {FIN;
	cin>>n;
	fore(i,1,n+1)cin>>a[i],sp[i]=sp[i-1]+a[i];
	ll res=1e18;
	fore(i,2,n-1) {
		ii l=get(1,i),r=get(i+1,n);
		res=min(res,get(l,r));
	}
	cout<<res<<endl;
}