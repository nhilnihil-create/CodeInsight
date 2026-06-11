#include<iostream>
#include<cstdio>
#include<algorithm>
/*
容易知道，每一轮T一定是能走就走。因为如果T不走，那么A就可以通过不走来强迫游戏结束。 
并且，如果P经过了一个障碍上方，游戏就结束了。所以A一定会尽可能地让P走到一个障碍上方。 
*/
struct data{
	int x;int y;
	inline bool operator<(const data &B){
		return x==B.x?y<B.y:x<B.x;
	}
	inline void init(int X,int Y){
		x=X,y=Y;
	}
}a[200005];
int n,h,w;
void init(){
	scanf("%d%d%d",&h,&w,&n);
	int x,y;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		a[i].init(x,y);
	}
	std::sort(a+1,a+1+n);
	int nw=0;
	for(int i=1;i<=n;++i){
		if(a[i].x-nw==a[i].y){
			++nw;
		}
		if(a[i].x-nw>a[i].y){
			printf("%d\n",a[i].x-1);
			return;
		}
	}
	printf("%d\n",h);
}

int main(){
	init();
	return 0;
}