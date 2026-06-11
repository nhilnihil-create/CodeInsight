#include <cstdio>
using namespace std;
const int N=100010;
typedef long long ll;
int n;
ll subsum;
int a[N],maxa;
int b[N];
inline int max(int x,int y){
	return x>y?x:y;
}
void readData(){
	scanf("%d",&n);
	subsum=1ll*n*(n+1)/2;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxa=max(maxa,a[i]);
	}
}
namespace BIT{
	int n;
	int a[N*2];
	void setup(int _n){
		n=_n;
		for(int i=1;i<=n;i++) a[i]=0;
	}
	void add(int u,int x=1){
		for(;u&&u<=n;u+=u&-u)
			a[u]+=x;
	}
	int que(int u){
		int res=0;
		for(;u;u-=u&-u)
			res+=a[u];
		return res;
	}
}
ll calc(int x){
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=(a[i]>=x)?1:-1;
		b[i]+=b[i-1];
	}
	BIT::setup(2*n+1);
	BIT::add(n+1);
	ll res=0;
	for(int i=1;i<=n;i++){
		res+=BIT::que(b[i]+(n+1));
		BIT::add(b[i]+(n+1));
	}
	return res;
}
bool judge(int x){
	return calc(x)>=((subsum+1)>>1);
}
int solve(){
	int l=1,r=maxa,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	return r;
}
int main(){
	readData();
	printf("%d\n",solve());
	return 0;
}
