#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100010;
const int INF=1e9;
int n;
int a[N];
inline int abs(int x){
	return x>=0?x:-x;
}
void readData(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}
void solve(){
	sort(a+1,a+1+n);
	int p=lower_bound(a+1,a+1+(n-1),(a[n]+1)>>1)-a;
	if(p==n)
		p--;
	if(!(a[n]&1)){
		int dis1=abs(a[p]-(a[n]>>1)),val1=a[p];
		int dis2=INF,val2=-1;
		if(p>1){
			p--;
			dis2=abs(a[p]-(a[n]>>1));
			val2=a[p];
		}
		printf("%d %d\n",a[n],dis1<=dis2?val1:val2);
	}
	else{
		int dis1=(a[p]>=((a[n]+1)>>1))?abs(a[p]-((a[n]+1)>>1)):abs(a[p]-(((a[n]+1)>>1)-1)),val1=a[p];
		int dis2=INF,val2=-1;
		if(p>1){
			p--;
			dis2=(a[p]>=((a[n]+1)>>1))?abs(a[p]-((a[n]+1)>>1)):abs(a[p]-(((a[n]+1)>>1)-1));
			val2=a[p];
		}
		printf("%d %d\n",a[n],dis1<=dis2?val1:val2);
	}
}
int main(){
	readData();
	solve();
	return 0;
}
