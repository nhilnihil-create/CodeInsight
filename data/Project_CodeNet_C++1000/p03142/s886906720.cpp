#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main(){
	int N, M; 
	cin >> N >> M; 
	int I[100010] = {}; 
	vector<int> E[100010] = {}; // 出ていく辺
	vector<int> F[100010] = {}; // 入ってくる辺
	for(int i = 1; i < M+N; i++){
		int a, b; 
		cin >> a >> b; 
		E[a].push_back(b); 
		F[b].push_back(a); 
		I[b] ++; 
	}
	stack<int> st;
	for(int i = 1; i <= N; i++){
		if(!I[i]) st.push(i); 
	}
	vector<int> S = {}; //トポロジカルソート後
	while(st.size()){
		int i = st.top(); st.pop(); 
		S.push_back(i); 
		for(int j = 0; j < E[i].size(); j++){
			I[E[i].at(j)] --; 
			if(!I[E[i].at(j)]) st.push(E[i].at(j)); 
		}
	}
	int top[100010] = {}; 
	for(int i = 0; i < N; i++){
		top[S.at(i)] = i; 
	}
	for(int i = 1; i <= N; i++){
		int mx = -1; 
		for(int j = 0; j < F[i].size(); j++){
			mx = max(mx, top[F[i].at(j)]);
		}
		cout << ((mx >= 0) ? S.at(mx) : 0) << endl; 
	}
}