#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;


P a[3000];
bool used[3000];
int root[3000];
priority_queue<int,vector<int>,greater<int>>dat[3000];
vector<int>dat2[3000];

void merge(int u,int v){
	u=root[u];v=root[v];
	if(u==v)return;
	if(dat2[u].size()<dat2[v].size())swap(u,v);
	while(!dat[v].empty()){
		int p=dat[v].top();dat[v].pop();
		dat[u].push(p);
	}
	for(int i:dat2[v]){
		root[i]=u;
		dat2[u].push_back(i);
	}
}

int main(){
	//O(Nlog^2N)
	int n,K,q;cin>>n>>K>>q;
	rep(i,n){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	rep(i,n){
		root[i]=i;
		dat[i].push(a[i].first);
		dat2[i].push_back(i);
	}
	sort(a,a+n,greater<>());
	priority_queue<int>que;
	int ans=INT_MAX;
	rep(i,n){
		P p=a[i];
		used[p.second]=true;
		if(p.second&&used[p.second-1]){
			merge(p.second-1,p.second);
		}
		if(p.second+1<n&&used[p.second+1]){
			merge(p.second+1,p.second);
		}
		while(dat[root[p.second]].size()>=K){
			int r=dat[root[p.second]].top();dat[root[p.second]].pop();
			que.push(r);
		}
		while(que.size()>q)que.pop();
		if(que.size()==q){
			ans=min(ans,que.top()-p.first);
		}
	}
	cout<<ans<<endl;
}