#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back

const int N = 200018;
const ll oo = 9e18;

int n, m;
vector<int> adj[N];
char c[N];
int qtd[N][2];
bool vis[N];

int main(){
	scanf("%d %d", &n, &m);
	scanf("%s", c+1);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d",&x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
		qtd[x][c[y] - 'A']++;
		qtd[y][c[x] - 'A']++;
	}

	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(!qtd[i][0] || !qtd[i][1]){
			q.push(i);
			vis[i] = 1;
		}
	}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i : adj[v]){
			if(!vis[i]){
				qtd[i][c[v] - 'A']--;
				if(qtd[i][c[v] - 'A'] == 0){
					q.push(i);
					vis[i] = 1;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			printf("Yes\n");
			return 0;	
		}
	}
	printf("No\n");
}
