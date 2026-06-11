#include <bits/stdc++.h>
using namespace std;

const int MAX = (int)2e5 + 5;

vector<int> graph[MAX];
bool visited[MAX];
string charNodes;
int cnt[MAX][2];
queue<int> invalidNodes;

void bfs(){
	while(!invalidNodes.empty()){
		int currentNode = invalidNodes.front();
		invalidNodes.pop();
		
		for(int i = 0; i < graph[currentNode].size(); i++){
			int currentNeighbour = graph[currentNode][i];
			
			if(visited[currentNeighbour]) continue;
			
			cnt[currentNeighbour][charNodes[currentNode] - 'A']--;
			
			if(cnt[currentNeighbour][0] == 0 || cnt[currentNeighbour][1] == 0){
				invalidNodes.push(currentNeighbour);
				visited[currentNeighbour] = 1;
			}
				
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	cin >> charNodes;
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		--a; --b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
		
		cnt[a][charNodes[b] - 'A']++;
		cnt[b][charNodes[a] - 'A']++;
	}
	
	
	for(int i = 0; i < n; i++){
		if(cnt[i][0] == 0 || cnt[i][1] == 0){
			invalidNodes.push(i);
			visited[i] = 1;
		}
	}
	
	bfs();
	
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}