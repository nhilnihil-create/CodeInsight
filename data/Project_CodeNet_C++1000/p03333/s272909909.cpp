#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int N=1e5+100;
int n,l[N],r[N];
set<ii> sl,sr;

ll solve(int xr){
	lop(i,n){
		sl.insert(ii(l[i],i));
		sr.insert(ii(r[i],i));
	}
	ll ret=0;
	int cur=0;
	for(int j=0;j<n;j++){
		int i,to=cur;
		if((j&1)^xr) i=sr.begin()->second;
		else i=sl.rbegin()->second;
		if(cur<l[i])to = l[i];
		else if(cur>r[i])to=r[i];
		ret+=abs(cur-to);
		cur=to;
		sr.erase(ii(r[i],i));
		sl.erase(ii(l[i],i));
	}
	return ret+abs(cur);
}
int main(){
#ifndef ONLINE_JUDGE
	//freopen("i.txt","r",stdin);
#endif
	sc(n);
	lop(i,n)
		sc(l[i]),sc(r[i]);
	cout<<max(solve(0),solve(1));

}
