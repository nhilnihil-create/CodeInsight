#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ll long long
int k,a[100001],vis[100001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int c[100001];
int main(){
	scanf("%d",&k);
	memset(a,0x3f,sizeof a);
	a[1]=1; pq.push(make_pair(1,1));
	while(!pq.empty()){
		pair<int,int> P=pq.top(); pq.pop();
		int u=P.second, d=P.first;
		if(vis[u]) continue;
		int v=(u+1)%k;
		if(a[v]>d+1) a[v]=d+1, pq.push(make_pair(a[v],v));
		for(int i=u;;i=i*10%k){
			if(c[i]||vis[i]) break;
			if(a[i]>d) a[i]=d, pq.push(make_pair(a[i],i));
			c[i]=1;
		}
		for(int i=u;;i=i*10%k){
			if(!c[i]) break;
			c[i]=0;
		}
		vis[u]=1;
	} printf("%d",a[0]);
	return 0;
}