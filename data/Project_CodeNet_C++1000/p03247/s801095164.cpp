#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,len,d[100010],a[100010],b[100010],f[2];
void solve(int x,int y){
	int i;
	for(i=1;i<=len;i++){
		if(abs(x)>abs(y)){
			if(x>0)printf("R"),x-=d[i];
			 else printf("L"),x+=d[i];
		}
		 else{
		 	if(y>0)printf("U"),y-=d[i];
		 	 else printf("D"),y+=d[i];
		 }
	}
	puts("");
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		f[(a[i]+b[i])%2]=1;
	}
	if(f[0]&&f[1])return puts("-1"),0;
	for(i=30;i+1;i--)d[++len]=1<<i;
	if(f[0])d[++len]=1;
	printf("%d\n",len);
	for(i=1;i<=len;i++)printf("%d ",d[i]);puts("");
	for(i=1;i<=n;i++)solve(a[i],b[i]);
}