#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int h,w,n;
int mh[200005];
int main() {
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=h;i++) mh[i] = h+1;
	for(int i=1;i<=n;i++) {
		int x,y; scanf("%d%d",&x,&y);
		mh[x] = min(mh[x],y);
	}
	int rr=1;
	if(rr>=mh[2]) {
		puts("1"); return 0;
	}
	for(int i=2;i<=h;i++) {
		if(rr<=mh[i]-2) rr++;
		if(rr>=mh[i+1]) {
			printf("%d",i); return 0;
		}
	}
	printf("%d",h);
}