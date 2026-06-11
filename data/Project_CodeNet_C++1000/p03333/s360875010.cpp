#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
const ll mod = 998244353;

int n,l[N],r[N];

set<pair<int,int> >L,R;
set<pair<int,int> >::iterator it;

ll move(int &p,int x){
	int ret=0;
	if(l[x]<=p&&p<=r[x])ret=0;
	else if(abs(l[x]-p)>abs(r[x]-p))ret=abs(r[x]-p),p=r[x];
	else ret=abs(l[x]-p),p=l[x];
	return ret;	
}

ll Solve(bool f){
	int p=0;
	ll ret=0;
	for(int i=1,x;i<=n;++i){
		if((i^f)&1){
			it=L.end();it--;
			x=it->second;
			ret+=move(p,x);
		}
		else{
			it=R.begin();
			x=it->second;
			ret+=move(p,x);
		}
		L.erase(make_pair(l[x],x));
		R.erase(make_pair(r[x],x));
	}
	ret+=abs(p); 
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]);
	ll ans[2];
	for(int f=0;f<2;++f){
		for(int i=1;i<=n;++i)L.insert(make_pair(l[i],i)),R.insert(make_pair(r[i],i));
		ans[f]=Solve(f);
	}
	printf("%lld\n",max(ans[0],ans[1])); 
}