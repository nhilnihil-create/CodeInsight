#include<bits/stdc++.h>
#define int long long
#define maxn 100005
#define pii pair<int,int>
using namespace std;
int N;
pii arr[maxn];
int sz[maxn];
vector<int> G[maxn];
int dfs(int u,int pa) {
	int ret = 0;
	for(int v:G[u])
		if(v!=pa)
			ret += sz[v]+dfs(v,u);
	return ret;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> arr[arr[i].second=i].first;
	sort(arr+1,arr+1+N);
	for(int i=1;i<=N;i++)
		sz[i] = 1;
	for(int i=N;i>1;i--) {
		int val = arr[i].first;
		int idx = arr[i].second;
		int pa_val = val-(N-sz[idx])+(sz[idx]);
		int tem = lower_bound(arr+1,arr+1+N,pii{pa_val,-1})-arr;
		if(tem>=i || arr[tem].first!=pa_val) {
			cout << -1 << endl;
			return 0;
		}
		int pa = arr[tem].second;
		sz[pa] += sz[idx];
		G[pa].emplace_back(idx);
	}
	if(dfs(arr[1].second,arr[1].second)==arr[1].first) {
		for(int u=1;u<=N;u++)
			for(int v : G[u])
				cout << u << " " << v << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}
