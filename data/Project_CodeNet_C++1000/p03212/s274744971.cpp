#include<cstdio>
#include<algorithm>
using namespace std;
int ans=0,n;
void dfs(int now,bool a,bool b,bool c){
	if(now>n||now<0) return;
	ans+=(a&&b&&c),dfs(now*10+3,1,b,c),dfs(now*10+5,a,1,c),dfs(now*10+7,a,b,1);
}
int main(){
	scanf("%d",&n),dfs(3,1,0,0),dfs(5,0,1,0),dfs(7,0,0,1),printf("%d",ans);
	return 0;
}
