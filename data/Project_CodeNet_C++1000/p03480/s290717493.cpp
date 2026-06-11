#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int n,m,i,j,a[100005],ans;
int l,r,mid,xr,p1,flag;
char s[100005];
int read(){
	char ch=getchar();
	int xx=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return xx;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		a[i]=s[i]-'0';
	l=n/2+1;r=n;mid=(l+r)/2;ans=n/2;
	while(l<=r){
		p1=n-mid+1;
		xr=0;
		for(i=1;i<=p1;i++)
			if(a[i]!=xr)
				xr^=1;
		flag=0;
		for(i=p1+1;i<=mid;i++)
			if(a[i]!=xr)
				flag=1;
		if(flag==0){
			ans=max(ans,mid);
			l=mid+1;
		}
		else
			r=mid-1;
		mid=(l+r)/2;
	}
	printf("%d\n",ans);
	return 0;
}