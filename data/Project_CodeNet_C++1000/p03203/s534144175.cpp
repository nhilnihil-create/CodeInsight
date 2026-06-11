#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxw 200020
using namespace std;
int h,w,n;
map<int,bool>mp[maxw];
void init(){
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=w;++i)mp[i][h+1]=1;
	for(int i=1;i<=n;++i){
		int x,y;scanf("%d%d",&x,&y);
		mp[y][x]=1;
	}
}
void solve(){
	int ans=h,j=0;
	for(int i=1;i<=h;++i){
		if((j<w)&&(!mp[j+1].count(i)))++j;
		ans=min(ans,(*mp[j].lower_bound(i)).first-1);
	}
	printf("%d\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}