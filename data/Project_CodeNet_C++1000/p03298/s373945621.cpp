#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
#define _rep(i,s,t) for(register int i=s;i>=t;--i)
using namespace std;
const int mod=998244353;
typedef long long ll;
int n;
char s[41];
char A[41],B[41];
int b[41];
ll f[39][39],ans;
map<int,int>mp;
inline void deal(int S){
	int top=0,hh=0;
	rep(i,0,n-1)if(S>>i&1)A[++top]=s[i+1];
	_rep(i,n-1,0)if((~S)>>i&1)A[++top]=s[i+1];
	rep(i,1,n)B[i]=A[i];
	reverse(B+1,B+n+1);
	//puts(A+1);
	rep(i,1,n)hh=(hh*97ll+(A[i]-'a'+1))%mod;
	if(mp[hh])return;
	mp[hh]=1;
	//puts(B+1);
	memset(f,0,sizeof f);
	f[0][0]=1;
	rep(i,0,n+n-1)
		rep(j,0,min(i,n)){
			if(!f[j][i-j])continue;
			if(A[j+1]==s[i+1])f[j+1][i-j]+=f[j][i-j];
			if(B[i-j+1]==s[i+1])f[j][i-j+1]+=f[j][i-j];
		}
	ans+=f[n][n];
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	scanf("%d%s",&n,s+1);
	rep(i,0,(1<<n)-1)
		deal(i);
	printf("%lld\n",ans);
	return 0;
}