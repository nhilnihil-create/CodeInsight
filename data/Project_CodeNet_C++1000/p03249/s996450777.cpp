#include <bits/stdc++.h>
#define PB push_back
#define MP std::make_pair
#define FI first
#define SE second
#define M 1000005
#define INF 1000000000
typedef long long ll;
ll n,D[M],size[M],sum;
std::multiset <std::pair <ll,ll> > Set;
std::pair <ll,ll> Edge[M];
ll read(){
	char c=getchar();ll ans=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') ans=ans*10+c-'0',c=getchar();
	return ans;
}
void Write(ll x){
	if (x<10) putchar(x+'0');
	else Write(x/10),putchar(x%10+'0');
	return;
}
int main(){
	n=read();
	for (ll i=1;i<=n;i++) size[i]=1,Set.insert(MP(D[i]=read(),i));
	for (ll i=1;i<n;i++){
		auto it=Set.end();--it;ll X=it->FI,Y=it->SE;Set.erase(it);
		auto nxt=Set.lower_bound(MP(X+size[Y]-(n-size[Y]),0));
		if (nxt==Set.end()||nxt->FI>X+size[Y]-(n-size[Y])) return !printf("-1");
		Edge[i]=MP(Y,nxt->SE),size[nxt->SE]+=size[Y]; 
	}
	for (int i=1;i<=n;i++) sum+=size[i]-1;
	if (sum!=Set.begin()->FI) return !printf("-1");
	for (int i=1;i<n;i++) Write(Edge[i].FI),putchar(' '),Write(Edge[i].SE),putchar('\n');
	return 0;
}
