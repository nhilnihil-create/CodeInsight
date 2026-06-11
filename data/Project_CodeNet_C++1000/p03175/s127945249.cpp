#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod ((int)1e9+7)

pair<int, int> dfs(vector<vector<int>> &graph, int curr_node, int parent){
	int w = 1, b = 1;
	for(int i = 0; i < graph[curr_node].size(); i++){
		if(graph[curr_node][i]!=parent){
			pair<int, int> temp = dfs(graph, graph[curr_node][i], curr_node);
			w = (((ll)temp.first+temp.second)*(ll)w)%mod;
			b = ((ll)temp.first*b)%mod;
		}
	}
	return make_pair(w, b);
}	

void test(vector<vector<int>> &graph){
	pair<int, int> answer = dfs(graph, 0, -1);
	cout << ((answer.first%mod) + (answer.second%mod))%mod << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/input.txt", "r", stdin);
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/output.txt", "w", stdout);
	#endif
	int n;
	pair<int, int> temp;
	cin >> n;
	vector<vector<int>> graph(n);
	for(int i = 0; i < n-1; i++){
		cin >> temp.first >> temp.second;
		graph[temp.first-1].push_back(temp.second-1);
		graph[temp.second-1].push_back(temp.first-1);
	}
	test(graph);
	return 0;
}