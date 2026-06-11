#include <bits/stdc++.h>
using namespace std;

#define maxn 300005
int n,a,b,c[maxn];

int main(){
	scanf("%d%d%d",&n,&a,&b);
	int ans=-1;
	for(int i=0;i<=n;++i)
		if(n-i+ceil(i*1.0/b)==a){
			ans=i;break;
		}
	if(a+b>n+1||ans==-1){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n-ans;++i)c[i]=i;
	int t=ans%b,cur=n-ans+1;
	for(int i=n-ans+t;i>n-ans;)c[i--]=cur++;
	for(int i=n-ans+t+b;i<=n;i+=b)
		for(int j=0;j<b;++j)
			c[i-j]=cur++;
	
	for(int i=1;i<n;++i)printf("%d ",c[i]);
	printf("%d\n",c[n]);
	
	return 0;
} 