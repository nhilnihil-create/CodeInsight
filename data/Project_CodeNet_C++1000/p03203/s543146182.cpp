#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	int x,y;
}a[500010];
int h,w,n,mx,i,mn[500010];
int main(){
	scanf("%d%d%d",&h,&w,&n);
	for(i=1;i<=h;i++)mn[i]=w+1;
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		mn[a[i].x]=min(mn[a[i].x],a[i].y);
		//mp[a[i].x][a[i].y]=1;
	}
	mx=1;
	for(i=1;i<h;i++){
		if(mn[i+1]<=mx){
			printf("%d\n",i);return 0;
		}
		if(mn[i+1]>mx+1)mx++;
	}
	printf("%d",h);
}