#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define ll long long 
using namespace std;

int n,i,j,k,a[maxn],d[maxn],v[maxn],w;

int check(int K){
	if (K==1){
		for(int i=2;i<=n;i++) if (a[i]<=a[i-1])
			return 0;
		return 1;
	}
	w=1,d[w]=a[1],v[w]=0;
	for(i=2;i<=n;i++) if (a[i]<=a[i-1]){
		while (d[w]>a[i]) w--;
		if (d[w]<a[i]) w++,d[w]=a[i],v[w]=1; else {
			for(j=a[i];j>=0;j--) if (w&&d[w]==j&&v[w]+1==K) w--;
			else {
				if (j==0) return 0;
				if (w==0||d[w]!=j) w++,d[w]=j,v[w]=1; else 
					v[w]++;
				break;
			}
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=n,mid,ans;
	while (l<=r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
}