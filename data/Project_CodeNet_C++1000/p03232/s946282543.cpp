#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

int read() {
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	int x=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

const int N=1e5+5,Mo=1e9+7;

int n,a[N],inv[N],ans;

int main() {
	n=read();
	fo(i,1,n) a[i]=read();
	inv[1]=1;fo(i,2,n) inv[i]=(ll)(Mo-Mo/i)*inv[Mo%i]%Mo;
	fo(i,2,n) (inv[i]+=inv[i-1])%=Mo;
	fo(i,1,n) {
		int res=inv[i];(res+=inv[n-i+1]-1)%=Mo;
		(ans+=(ll)res*a[i]%Mo)%=Mo;
	}
	fo(i,1,n) ans=(ll)ans*i%Mo;
	printf("%d\n",ans);
	return 0;
}