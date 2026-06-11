#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;

map<LL,int> qaq;

void DSY(){
	puts("-1");
	exit(0);
}

int sz[N];

vector<int> es[N];
LL dd[N]={0};
LL d[N];
void dsy(int x,int fa=-1){
	for(vector<int>::iterator it=es[x].begin();it!=es[x].end();++it){
		if(*it==fa)continue;
		dsy(*it,x);
		dd[x]+=dd[*it]+sz[*it];
	}
}

vector<pair<int,int> > ess;
void ae(int u,int v){
	if(u>v)swap(u,v);
	ess.push_back(pair<int,int>(u,v));
	es[u].push_back(v);
	es[v].push_back(u);
}
void print(){
	sort(ess.begin(),ess.end());
	for(vector<pair<int,int> >::iterator it=ess.begin();it!=ess.end();++it){
		printf("%d %d\n",it->first,it->second);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&d[i]);
		qaq[d[i]]=i;
		sz[i]=1;
	}
	int cnt=n;
	for(map<LL,int>::reverse_iterator it=qaq.rbegin();it!=qaq.rend();++it){
		int x=it->second;
		LL ddd=it->first;
		if(sz[x]*2==n)DSY();
		LL nd=ddd+sz[x]-(n-sz[x]);
		if(cnt==1){
			dsy(x);
			if(dd[x]!=d[x])DSY();
			break;
		}
		if(!qaq.count(nd)){
			DSY();
		}else{
			int v=qaq[nd];
			ae(x,v);
			sz[v]+=sz[x];
		}
		cnt--;
	}
	print();
	return 0;
}