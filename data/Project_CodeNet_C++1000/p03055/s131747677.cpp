#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[200005];
int dst[200005],vstd[200005];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int now=1;dst[1]=1;
	queue<int>q;
	q.push(now);
	while(q.size()){
		int node=q.front();
		q.pop();
		if(vstd[node])continue;
		vstd[node]=true;
		for(auto u:v[node]){
			if(!vstd[u]){
				dst[u]=dst[node]+1;
				q.push(u);
			}
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		if(dst[i]>mx){
			now=i;
			mx=dst[i];
		}
	}
	dst[now]=1;memset(vstd,0,sizeof vstd);
	q.push(now);
	while(q.size()){
		int node=q.front();
		q.pop();
		if(vstd[node])continue;
		vstd[node]=true;
		for(auto u:v[node]){
			if(!vstd[u]){
				dst[u]=dst[node]+1;
				q.push(u);
			}
		}
	}
	mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,dst[i]);
	}
	if(mx%3!=2){
		cout<<"First";
	}else{
		cout<<"Second";
	}
	return 0;
}