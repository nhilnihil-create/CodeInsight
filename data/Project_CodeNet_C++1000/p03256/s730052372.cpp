#include<bits/stdc++.h>
using namespace std;

int cntA[200001],cntB[200001];
vector<int> e[200001];
bool vis[200001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	string s;
	cin>>n>>m>>s;
	s.insert(0," ");
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
		if(s[v]=='A')
			cntA[u]++;
		else
			cntB[u]++;
		if(s[u]=='A')
			cntA[v]++;
		else
			cntB[v]++;
	}
	queue<int> q;
	int cnt = 0;
	for(int i=1;i<=n;i++)
		if(cntA[i]==0||cntB[i]==0)
			q.emplace(i),vis[i]=true;
	while(!q.empty()){
		int x = q.front();q.pop();
		cnt++;
		for(int it:e[x]){
			if(s[x]=='A')
				cntA[it]--;
			else
				cntB[it]--;
			if(!vis[it])
				if(cntA[it]==0||cntB[it]==0)
					q.emplace(it),vis[it]=true;
		}
	}
	if(cnt==n)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
}
