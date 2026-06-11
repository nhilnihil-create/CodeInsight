#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int N=100005;
long long d[N],m[N],dist[N];int id[N];
map<long long,int> ma;
bool cmp1(int i,int j){return d[i]>d[j];}
vector<int> ansu,ansv;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",d+i);
		id[i]=i;m[i]=1;
		ma[d[i]]=i;
	}
	sort(id+1,id+1+n,cmp1);
	for(int i=1;i<n;i++){
		long long dv=d[id[i]]+2*m[id[i]]-n;
		if(ma[dv]==0){puts("-1");return 0;}
		int v=ma[dv];
		ansu.push_back(id[i]);
		ansv.push_back(v);
		m[v]+=m[id[i]];
		dist[v]+=dist[id[i]]+m[id[i]];
	}
	if(dist[id[n]]!=d[id[n]]) puts("-1");
	else
		for(int i=0;i<ansu.size();i++) printf("%d %d\n",ansu[i],ansv[i]);
}