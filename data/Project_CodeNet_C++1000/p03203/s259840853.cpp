#include <stdio.h>
#include <set>
#define MN 200000
#define mpair(a,b) std::make_pair(a,b)
int n,m,c,q[MN+5],ans;
std::set<std::pair<int,int>> s;
bool ck(int x,int y){
	if(x>n||y>m) return false;
	return s.find(mpair(x,y))==s.end();
}
bool down(int &x,int y){
	if(!ck(x+1,y)) return false;
	x++; return true;
}
int main(){
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=c;i++){
		static int x,y;
		scanf("%d%d",&x,&y);
		s.insert(mpair(x,y));
	}
	int x=1;
	for(int y=1;y<=m;y++){
		q[y]=x;
		if(!down(x,y)) break;
		while(!ck(x,y+1)) if(!down(x,y)) break;
		if(!ck(x,y+1)) break;
	}
	ans=n;
	for(auto it=s.begin();it!=s.end();it++){
		if(q[it->second]!=0&&it->first>q[it->second])
			ans=std::min(ans,it->first-1);
	}
	printf("%d\n",ans);
}