#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> ans;
int n;

vector<vector<int>>gr;

void dfs(int v) {
    visited[v] = true;
    for (int u : gr[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort(vector<vector<int>>g) {
    visited.assign(n+1, false);
    ans.clear();
    gr=g;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int m;
	
	cin>>n>>m;
	int i,j,k;
	int a,b;
	
	vector<vector<int>>g(n+1);
	vector<vector<int>>an(n+1);
	
	int pn[n+1]={0};
	int p[n+1];
	
	for(i=1;i<n+m;i++)
	{
	    cin>>a>>b;
	        g[a].push_back(b);
	        an[b].push_back(a);
	}
	
	topological_sort(g);
	
	map<int,int>mp;
	for(i=0;i<n;i++)
	{
	    mp[ans[i]]=i;
	}
	
	for(i=1;i<=n;i++)
	{
	    a=-1;
	    //cout<<i<<endl;
	    for(int c : an[i])
	    {
	        if(a<mp[c])
	        a=mp[c];
	        
	        //cout<<c<<" : "<<mp[c]<<endl;
	    }
	    if(an[i].size()==0)
	    p[i]=0;
	    else
	    p[i]=ans[a];
	}
	
	
	for(i=1;i<=n;i++)
	{
	    cout<<p[i]<<endl;
	}
	return 0;
	
}
