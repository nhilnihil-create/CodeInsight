#include <cstdio>
#include <algorithm>
using namespace std;
const int N=200010;
int n;
int a[N],b[N],maxw;
int c[N],d[N];
void readData(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxw=max(maxw,a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		maxw=max(maxw,b[i]);
	}
}
inline int bit(int i){
	return 1<<i;
}
int calc(int l,int r){ // [l,r]
	return upper_bound(d+1,d+1+n,r)-lower_bound(d+1,d+1+n,l);
}
void solve(){
	int ans=0;
	for(int k=0;(1<<k)<=(maxw<<1);k++){
		int t=1<<k;
		for(int i=1;i<=n;i++){
			c[i]=a[i]%(t<<1);
			d[i]=b[i]%(t<<1);
		}
		sort(c+1,c+1+n);
		sort(d+1,d+1+n);
		for(int i=1;i<=n;i++){
			int sum=calc(t-c[i],t*2-1-c[i])+calc(t*3-c[i],t*4-1-c[i]);
			ans^=t*(sum&1);
		}
	}
	printf("%d\n",ans);
}
int main(){
	readData();
	solve();
	return 0;
}
