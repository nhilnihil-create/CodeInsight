#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long int ll;

vector<int> G[100100];
int to[100100];

int main(){
	int n,m; cin >> n >> m;
	vector<int> a(n+m-1),b(n+m-1);
	for(int i=0;i<n+m-1;i++){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		G[a[i]].push_back(b[i]);
		to[b[i]]++;
	}
	int parent;
	for(int i=0;i<n;i++){
		if(to[i]==0)parent=i;
	}
	vector<int> dist(n,0);
	queue<int> q;
	q.push(parent);
	while(q.empty()==false){
		int v=q.front();
		q.pop();
		for(int p:G[v]){
			to[p]--;
			dist[p]=max(dist[p],dist[v]+1);
			if(to[p]==0){
				q.push(p);
			}
		}
	}
	vector<int> par(n,-1);
	for(int i=0;i<n+m-1;i++){
		int f=a[i]; int t=b[i];
		if(dist[t]-dist[f]==1){
			par[t]=f;
		}
	}
	for(int i=0;i<n;i++){
		cout << par[i]+1 << endl;
	}
}