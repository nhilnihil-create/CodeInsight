#include<bits/stdc++.h>
#define N 100005 
using namespace std;
int n,m,c[N];
void Add(int x,int d){
	for(int i=x;i<=n+1;i+=i&-i)c[i]+=d;
}
int sum(int x){
	int ans=0;
	for(int i=x;i;i-=i&-i)ans+=c[i];
	return ans;
}
int main()
{	
	scanf("%d%d",&n,&m);
	int tot=0;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,1);Add(y+1,-1);
	}
	for(int i=1;i<=n;i++){
		if(sum(i)==m)tot++;
	}
	cout<<tot;
}