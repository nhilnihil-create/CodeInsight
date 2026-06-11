#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

struct BIT{
	int siz=1<<18;
	int a[(1<<18)+10];
	void init(){
		for(int i = 0 ; i < (1<<18)+10 ; i ++){
			a[i] = 0;
		}
	}
	void add(int x){
		while(x<=siz){
			a[x]++;
			x+=x&-x;
		}
	}
	int sum(int x){
		int ret = 0;
		while(x>0){
			ret += a[x];
			x -= x&-x;
		}
		return ret;
	}
}bit[2];

int main(){
	static ll n;
	static ll a[100010];
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	int l=0,r=1000000000;
	while(l<r){
		int m=(l+r+1)/2;
		bit[0].init();
		bit[1].init();
		ll ret=0;
		ll cnt=0;
		bit[0].add(cnt+n);
		for(int i=1;i<=n;i++){
			if(a[i]>=m)cnt++;
			if(i&1){
				ret+=bit[1].sum(cnt-i/2+n);
				ret+=bit[0].sum(cnt-i/2+n-1);
			}
			else {
				ret+=bit[0].sum(cnt-i/2+n);
				ret+=bit[1].sum(cnt-i/2+n);
			}
			bit[i&1].add(cnt-i/2+n);
			//cout<<i<<" "<<cnt-i/2+n<<endl;
		}
		//cout<<m<<" "<<ret<<endl;
		if(ret>=((n+1)*n/2+1)/2)l=m;
		else r=m-1;
	}
	cout<<l<<endl;
}

