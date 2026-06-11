#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const int MO=998244353;
int n;
LL ans,A,B,K,fac[500010],inv[500010];
LL pw(LL x,LL y){
	LL t=1;
	for (;y;y>>=1){
		if (y&1) t=t*x%MO;
		x=x*x%MO;
	}
	return t;
}
LL C(int x,int y){
	return fac[x]*inv[y]%MO*inv[x-y]%MO;
}
int main(){
	fac[0]=1;
	FOR(i,1,500000) fac[i]=fac[i-1]*i%MO;
	inv[500000]=pw(fac[500000],MO-2);
	FORD(i,499999,0) inv[i]=inv[i+1]*(i+1)%MO;
	cin>>n>>A>>B>>K;
	FOR(i,0,n){
		LL t=K-A*i;
		if (t<0) continue;
		if (t%B!=0) continue;
		LL j=t/B;
		if (j<0 || j>n) continue;
		(ans+=C(n,i)*C(n,j))%=MO;
	}
	ans=(ans%MO+MO)%MO;
	cout<<ans<<endl;
	return 0;
}