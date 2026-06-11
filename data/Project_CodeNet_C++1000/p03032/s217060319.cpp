#include<bits/stdc++.h>
using namespace std;
int v[55];
int temp[55];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	int ans=0;
	for(int l=0;l<=n;l++){
		for(int r=n+1;r>l;r--){
			int cnt=0,sum=0;
			for(int i=1;i<=l;i++)
				temp[++cnt]=v[i];
			for(int i=n;i>=r;i--)
				temp[++cnt]=v[i];
			if(k<cnt)	
				continue;
			sort(temp+1,temp+cnt+1);
			for(int i=cnt;i>=0;i--){
				if(i<=k-cnt)
					sum+=max(temp[i],0);
				else sum+=temp[i];
			}
			ans=max(ans,sum);
		}
	}
	printf("%d\n",ans);
}