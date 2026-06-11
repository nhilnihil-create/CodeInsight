#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=100005;
int n,a[N],ans,inv[N],sum,tmp,pre[N],jc;
void up(int &x,int y){x=x-mod+y;x=(x<0)?x+mod:x;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	inv[0]=inv[1]=pre[1]=1;jc=1;
	for (int i=2;i<=n;i++) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jc=(ll)jc*i%mod,pre[i]=((ll)pre[i-1]+inv[i])%mod;
	for (int i=1;i<=n;i++)
	{
		int tmp=0;up(tmp,pre[i]);up(tmp,pre[n-i+1]);
		up(ans,(ll)(tmp-1)*a[i]%mod);
	}
	printf("%d\n",(ll)ans*jc%mod);
	return 0;
}