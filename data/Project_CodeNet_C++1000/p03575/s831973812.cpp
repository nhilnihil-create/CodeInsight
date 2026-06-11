#include <bits/stdc++.h>
using namespace std;
bool G[55][55];
int main() {
	int n,m;
	cin >> n >> m;
	int a[m],b[m];
	for(int i=0;i<m;i++){
		cin >> a[i] >> b[i];
		G[a[i]-1][b[i]-1]=true;
		G[b[i]-1][a[i]-1]=true;
	}
	int count=0;
	for(int i=0;i<m;i++){
		G[a[i]-1][b[i]-1]=false;
		G[b[i]-1][a[i]-1]=false;
		vector<int> dist(n,-1);
		queue<int> que;
		dist[0]=0;
		que.push(0);
		while(!que.empty()){
			int v=que.front();
			que.pop();
			for(int j=0;j<n;j++){
				if(G[v][j]){
					if(dist[j]!=-1) continue;
					else{
						que.push(j);
						dist[j]=dist[v]+1;
					}
				}
			}
		}
		bool flag=true;
		for(int i=0;i<n;i++){
			if(dist[i]==-1) flag=false;
		}
		if(!flag) count++;
		G[a[i]-1][b[i]-1]=true;
		G[b[i]-1][a[i]-1]=true;
	}
	cout << count << endl;
}
