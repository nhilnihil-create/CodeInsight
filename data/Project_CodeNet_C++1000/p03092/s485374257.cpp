#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=5005;
int n,A,B,a[N];
ll f[N];
int main(){
	scanf("%d%d%d",&n,&A,&B);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) f[i]=1ll<<60;
	For(i,1,n){
		ll S=0;
		Rep(j,i-1,1){
			if (a[j]<a[i])
				f[i]=min(f[i],f[j]+S);
			S+=(a[j]<a[i]?B:A);
		}
		f[i]=min(f[i],S);
	}
	ll ans=1ll<<60;
	For(i,1,n){
		ll S=0;
		For(j,i+1,n)
			S+=(a[j]<a[i]?B:A);
		ans=min(ans,f[i]+S);
	}
	printf("%lld\n",ans);
}