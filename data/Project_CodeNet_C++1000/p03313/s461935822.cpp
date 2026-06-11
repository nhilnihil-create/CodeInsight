#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,j,hh,ans,mx,f[500001][2],a[500001];
int main(){
	scanf("%d",&n);
	for(i=0;i<(1<<n);i++){
	 scanf("%d",&a[i]);
	 f[i][0]=a[i];
  }
    mx=1<<n;
    for(i=0;i<n;i++)
     for(j=1;j<mx;j++)if(j&(1<<i)){
     	hh=j^(1<<i);
     	if(f[hh][0]>f[j][0]){
     		if(f[hh][1]>f[j][0])f[j][1]=f[hh][1];
     		 else f[j][1]=f[j][0];
     		f[j][0]=f[hh][0];
		 }
		  else if(f[hh][0]>f[j][1])f[j][1]=f[hh][0];
	 }
	for(i=1;i<mx;i++){
		
		ans=max(ans,f[i][0]+f[i][1]);
		printf("%d\n",ans);
	}
}