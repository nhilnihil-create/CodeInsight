#include <bits/stdc++.h>
#include <algorithm>
#include <stack>
using namespace std; 
int sign[100010]; 
vector<int> E[100010] = {}; 
int pos = 0; int neg = 0; 
int N, M; 
bool possible = true; 
void dfs(int a, int pm){
	sign[a] = pm; 
	int s = E[a].size(); 
	for(int i = 0; i < s; i++){
		if(sign[E[a].at(i)] == pm) {possible = false; return;}
		else if(sign[E[a].at(i)] == -pm) continue; 
		else{
			dfs(E[a].at(i), -pm); 
		}
	}
	return; 
}
int main(){
	cin >> N >> M; 
	for(int i = 0; i < M; i++){
		int a, b; 
		cin >> a >> b; 
		E[a].push_back(b); 
		E[b].push_back(a); 
	}
  	dfs(1, 1); 
	if(!possible) cout << (long long) N * (N-1) / 2 - M << endl; 
	else{
		for(int i = 1; i <= N; i++){
			if(sign[i] > 0) pos ++; 
			else if(sign[i] < 0) neg ++; 
		}	 
		cout << (long long) pos * neg - M << endl; 
	}
}