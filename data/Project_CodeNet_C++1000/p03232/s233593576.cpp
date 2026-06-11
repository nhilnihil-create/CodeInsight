#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gt getchar()
#define ll long long
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
typedef std::pair<int,int> P;
#define mk std::make_pair
#define fr first
#define sc second
inline int in()
{
	int k=0;char ch=gt;bool p=1;
	while(ch<'-')ch=gt;if(ch=='-')ch=gt,p=0;
	while(ch>'-')k=k*10+ch-'0',ch=gt;
	return p?k:-k;
}
const int YL=1e9+7,N=2e6+5;
inline int MO(const int &x){return x>=YL?x-YL:x;}
int inv[N];
int main()
{
	int n=in(),ans=0;inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=YL-1ll*(YL/i)*inv[YL%i]%YL;
	for(int i=2;i<=n;++i)inv[i]=MO(inv[i]+inv[i-1]);
	for(int i=1;i<=n;++i)ans=(1ll*in()*(inv[i]+inv[n-i+1]-1)+ans)%YL;
	for(int i=2;i<=n;++i)ans=1ll*ans*i%YL;
	printf("%d\n",ans);
	return 0;
}
