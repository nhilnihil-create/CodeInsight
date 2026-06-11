#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+2;
int N;
int a[MAX_N],b[MAX_N];
int c[MAX_N];
vector<int> G[MAX_N];
ll tot = 0;
int ans[MAX_N];
bool vis[MAX_N];

void add_edge(int fr, int to)
{
	G[fr].push_back(to);
	G[to].push_back(fr);
}

void bfs(int s, int at)
{
	ans[s] = c[at++];
	queue<int> que;
	que.push(s);
	vis[s] = true;
	while(!que.empty()){
		int cur = que.front(); que.pop();
		for(int nxt : G[cur]){
			if(!vis[nxt]){
				ans[nxt] = c[at++];
				tot += ans[nxt];
				que.push(nxt);
				vis[nxt]=true;
			}
		}
	}
}

void solve()
{
	sort(c+1, c+N+1, greater<int>());
	for(int i=0;i<N-1;++i) add_edge(a[i], b[i]);
	int root = -1;
	for(int i=1;i<=N;++i)if(root == -1 || G[i].size() > G[root].size()) root = i;
	bfs(root, 1);
	cout << tot << '\n';
	for(int i=1;i<=N;++i) cout<<ans[i]<<' ';
	cout<<'\n';
}

int main()
{
	cin >> N;
	for(int i=0;i<N-1;++i){
		cin >> a[i] >> b[i];
	}
	for(int i=1;i<=N;++i) cin >> c[i];
	solve();
	return 0;
}