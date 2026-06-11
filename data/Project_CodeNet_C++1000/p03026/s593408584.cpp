#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
	int n;
	cin>>n;
	vector<vector<int>> adj(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> c(n);
	rep(i,n) cin>>c[i];
	sort(all(c), greater<int>());

	const int root=0;
	int max_sum=0,idx=0;
	vector<int> max_w(n,-1);
	queue<int> que;
	que.push(root);
	max_w[root]=c[idx++];

	while(!que.empty()){
		int cur=que.front();que.pop();
		for(auto u : adj[cur]){
			if(max_w[u]!=-1) continue;
			max_w[u]=c[idx++];
			max_sum+=min(max_w[cur],max_w[u]);
			que.push(u);
		}
	}
	cout<<max_sum<<endl;
	rep(i,n) cout<<max_w[i]<<" ";

}