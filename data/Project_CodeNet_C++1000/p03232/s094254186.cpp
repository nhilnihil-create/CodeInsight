#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 1000000
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int mod=1e9+7;
int a[N],s[N];
inline int qpow(int x,int y)
{int A=1;for(;y;y>>=1,x=(ll)x*x%mod)if(y&1)A=(ll)A*x%mod;return A;}
int main()
{	int n,fac=1,ans=0; cin>>n;
	for(rint i=1;i<=n;i++) scanf("%d",&a[i]);
	for(rint i=1;i<=n;i++) fac=(ll)fac*i%mod;
	for(rint i=1;i<n;i++) s[i]=(s[i-1]+(ll)fac*qpow(i+1,mod-2)%mod)%mod;
	for(rint i=1;i<=n;i++) (ans+=(ll)a[i]*((ll)fac+s[i-1]+s[n-i])%mod)%=mod;
	cout<<ans;
	return 0;
}
