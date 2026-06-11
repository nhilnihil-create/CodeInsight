    #include<bits/stdc++.h>
    #define LL long long
    #define clr(x,i) memset(x,i,sizeof(x))
    using namespace std;
    const int N=200005;
    int n,m,ind[N][2],vis[N];
    vector<int> G[N];
    char s[N];
    queue<int> q;
    int main()
    {
    	ios::sync_with_stdio(0);
    	cin>>n>>m>>s+1;
    	//cout<<s+1<<endl;
    	for(int i=1;i<=m;i++){
    		int u,v; cin>>u>>v;
    		G[u].push_back(v); G[v].push_back(u);
    		ind[u][s[v]-'A']++; ind[v][s[u]-'A']++;
    	}
    	int tot=0;
    	for(int i=1;i<=n;i++){
    		if(!ind[i][0]||!ind[i][1]) q.push(i),vis[i]=1;
    	}
    	while(!q.empty()){
    		int u=q.front(); q.pop(); tot++;
    		for(int i=0;i<G[u].size();i++){
    			int v=G[u][i];
    			if(!(--ind[v][s[u]-'A'])&&!vis[v]) q.push(v),vis[v]=1;
    		}
    	}
    	if(tot<n) puts("Yes");
    	else puts("No");
    	return 0;
    }