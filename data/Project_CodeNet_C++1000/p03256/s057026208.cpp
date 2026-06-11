#include <bits/stdc++.h>
#include <set>
#include <stack>
using namespace std;
int N, M; 
vector<int> E[400010]; 
int visited[400010]; 
int main(){
	string S; 
	cin >> N >> M >> S; 
	set<pair<int, int>> T;
	for(int i = 0; i < M; i++){
		int a, b; cin >> a >> b; 
		a--; b--; 
		if(a > b) swap(a, b); 
		T.insert(make_pair(a, b)); 
	}
	int In[400010] = {};
	for(auto it = T.begin(); it != T.end(); it++){
		int a = (*it).first; int b = (*it).second; 
		if(S[a] == 'A' && S[b] == 'A'){
			E[2*a+1].push_back(2*b); In[2*b] ++; 
			if(a!= b) {
				E[2*b+1].push_back(2*a); In[2*a] ++; 
			}
		}
		if(S[a] == 'A' && S[b] == 'B'){
			E[2*a].push_back(2*b); In[2*b] ++; 
			E[2*b+1].push_back(2*a+1); In[2*a+1] ++; 
		}
		if(S[a] == 'B' && S[b] == 'A'){
			E[2*a+1].push_back(2*b+1); In[2*b+1] ++; 
			E[2*b].push_back(2*a); In[2*a] ++; 
		}
		if(S[a] == 'B' && S[b] == 'B'){
			E[2*a].push_back(2*b+1); In[2*b+1] ++; 
			if(a != b){
				E[2*b].push_back(2*a+1); In[2*a+1] ++; 
			}
		}
	}
	stack<int> st;
	for(int i = 0; i < N*2; i++){
		if(!In[i]) st.push(i); 
	}
	vector<int> Top = {}; //トポロジカルソート後
	while(st.size()){
		int i = st.top(); st.pop(); 
		Top.push_back(i); 
		for(int j = 0; j < E[i].size(); j++){
			In[E[i].at(j)] --; 
			if(!In[E[i].at(j)]) st.push(E[i].at(j)); 
		}
	}
	cout << ((Top.size() == N*2) ? "No" : "Yes") << endl;
}