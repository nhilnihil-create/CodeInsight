#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,q,a[2005],b[2005],tmp[2005],lt,lc,vis[2005],c[2005],ans=1e9;
signed main(){
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	vis[n+1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) if(a[j]<b[i]) vis[j]=1;
		lt=lc=0;
		for(int j=1;j<=n+1;++j){
			if(vis[j]){
				if(lt>=k){
					sort(tmp+1,tmp+lt+1);
					for(int m=1;m<=lt-k+1;++m){
						c[++lc]=tmp[m];
					}
				}
				lt=0;
			}
			else tmp[++lt]=a[j];
		}
		if(lc>=q){
			sort(c+1,c+lc+1);
			ans=min(ans,c[q]-b[i]);
		}
	}
	cout<<ans;
}