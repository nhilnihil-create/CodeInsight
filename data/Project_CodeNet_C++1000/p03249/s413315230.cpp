#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define NO return printf("-1"),0
using namespace std;
const int N=1e5+5;
int n,b[N][2],bs,sz[N];
ll w[N],su;
vector<int>e[N];
unordered_map<ll,int>A;
void find(int x,int len){
	su+=len;
	for(int i:e[x])find(i,len+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	fo(i,1,n)cin>>w[i],A[w[i]]=i,sz[i]=1;
	sort(w+1,w+n+1);
	fd(i,2,n){
		int x=A[w[i]],y;
		if(sz[x]*2>=n)NO;
		y=A[w[i]-n+sz[x]*2];
		if(!y)NO;
		++bs;b[bs][0]=x;b[bs][1]=y;
		sz[y]+=sz[x];
		e[y].push_back(x);
	}
	find(A[w[1]],0);
	if(su!=w[1])NO;
	fo(i,1,bs)printf("%d %d\n",b[i][0],b[i][1]);
}