#include<bits/stdc++.h>
using namespace std;

// Start
template<int SZ> struct UF{
	int p[SZ+1],sz[SZ+1];
	UF(){I(SZ);}
	void I(int n){for(int i=0;i<=n;i++)	sz[p[i]=i]=1;}
	int F(int x){return x==p[x]?x:p[x]=F(p[x]);}
	bool U(int x,int y){
		x=F(x),y=F(y);
		if(x==y)	return false;
		if(sz[x]<sz[y])	swap(x,y);
		return p[y]=x,sz[x]+=sz[y],true;
	}
};
// End

const int maxn = 1e5;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	UF<maxn> D;
	int n,m;
	cin>>n>>m;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		D.U(x,y);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(D.F(i)==i)
			ans++;
	cout<<ans<<endl;
}
