#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
}a[220000];
int h,w,n;
bool cmp(node x,node y){
	return x.x<y.x;
}
int main(){
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);
	int x=1,y=1;
	for(int i=1;i<=n;i++){
		if(a[i].x-x>a[i].y-y){
			printf("%d\n",a[i].x-1);
			return 0;
		}
		y=min(a[i].y-1,y+a[i].x-x);
		x=a[i].x;
	} 
	printf("%d",h);
}