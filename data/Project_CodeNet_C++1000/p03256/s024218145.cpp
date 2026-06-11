/*input
2 3
AB
1 1
1 2
2 2
*/

#include<bits/stdc++.h>
using namespace std;
#define mx 200005
char st[mx];
multiset<int> mst[mx];
set<int> edge[mx];
int vis[mx];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", st+1);
	for(int i = 0; i<m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		if(edge[u].count(v));else{
			mst[u].insert(st[v]);
			mst[v].insert(st[u]); 
		}
		edge[u].insert(v);
		edge[v].insert(u);
	}
	queue<int> Q;
	for(int i = 1; i<=n; i++)
	{
		if(mst[i].count('A') == 0 || mst[i].count('B') == 0){
			Q.push(i);
			vis[i] = 1;
			// cout << i << endl;
		}
	}
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for(int v : edge[u])
		{
			// assert(vis[v]);
			if(vis[v]) continue;
			if(u==11){
				// cout << v << endl;
			}
				// if(v==12){
					// cout << "hi " << mst[v].size() << endl;
					// for(int x : mst[v])
					// 	cout << char(x) << endl;
				// }
			if(v != u){
				mst[v].erase(mst[v].find(st[u]));
				edge[v].erase(edge[v].find(u));
				if(mst[v].count('A') == 0 || mst[v].count('B') == 0){
					vis[v] = 1;
					// cout << v << endl;
					Q.push(v);
				}
			}
		}
		edge[u].clear();
		mst[u].clear();
	}
	int cnt = 0;
	for(int i = 1; i<=n; i++)
	{
		if(!vis[i]){
			printf("Yes\n");
			// cout << i << endl;
			return 0;
		}
	}
	printf("No\n");
	return 0;
}