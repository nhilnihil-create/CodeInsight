#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int H,W,n,x,y,i,mn[N];
int main(){
	scanf("%d%d%d",&H,&W,&n);
	for(i=1;i<=H;++i)mn[i]=1<<30;
	for(i=1;i<=n;++i)scanf("%d%d",&x,&y),mn[x]=min(mn[x],y);
	for(i=2,y=1;i<=H;++i){
		if(y>=mn[i])break;
		y+=y+1<mn[i];
	}
	printf("%d\n",i-1);
	return 0;
}