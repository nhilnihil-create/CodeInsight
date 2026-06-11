#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int N=2e5+10;
vector<int>g[N];
int main(){
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<int>a(n);
	vector<int>b(n);
	
	int u, v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		u--,v--;
		g[u].push_back(v);
		g[v].push_back(u);
		if(s[u]==s[v]){
			if(s[u]=='A')a[u]++,a[v]++;
			else b[u]++,b[v]++;
		}
		else{
			if(s[u]=='A')b[u]++,a[v]++;
			else a[u]++,b[v]++;
		}
	}
	queue<int>q;
	vector<int>d(n);
	for(int i=0;i<n;i++)
		if(!a[i]||!b[i]){
			q.push(i);
			d[i]=1;
		}
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:g[u])
			if(!d[v]){
				if(s[u]=='A')a[v]--;
				else b[v]--;
				if(!a[v]||!b[v]){
					d[v]=1;
					q.push(v);
				}
			}
	}
	for(int i=0;i<n;i++)
		if(!d[i]){
			cout<<"Yes\n";
			return 0;
		}
	cout<<"No\n";
	
}


