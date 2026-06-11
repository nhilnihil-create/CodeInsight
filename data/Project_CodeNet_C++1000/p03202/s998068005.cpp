#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+100;
int a[N],d[N],f[N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		d[0]=0;
		bool pd=true;
		for(int i=1;i<=n;i++){
			if(a[i]<=a[i-1]){
				while(d[0]&&d[d[0]]>a[i]) d[0]--;
				if(d[d[0]]!=a[i]) d[++d[0]]=a[i],f[d[0]]=0;
				f[d[0]]++;
				while(f[d[0]]==mid){
					if(d[d[0]]==1) {pd=false;break;}
					d[0]--;
					int t=d[d[0]+1]-1;
					if(d[d[0]]!=t) d[++d[0]]=t,f[d[0]]=0;
					f[d[0]]++; 
				}
				if(!pd) break;
			}
		}
		if(pd) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}