#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

// トポロジカルソート(O(V+E))
// hは入次数リスト
vector<int> topologicalSort(vector<vector<int>> &to, vector<int> h){
	int n = h.size();
	stack<int> st; // 入次数0の頂点集合
	rep(i,n) if(h[i] == 0) st.push(i);
	
	vector<int> res;
	while(st.size()){
		int i = st.top();
		st.pop();
		res.push_back(i);
		for(auto j : to[i]){
			h[j]--;
			if(h[j] == 0) st.push(j);
		}
	}
	
	// 閉路検出
	rep(i,n){
		if(h[i] > 0) cout << "閉路検出: " << i << endl;
	}
	
	return res;
}

int main(){
	
	int n,m;
	cin >> n >> m;
	
	vector<vector<int>> to(n), from(n);
	vector<int> h(n);
	
	rep(i,n-1+m){
		int s,t;
		cin >> s >> t;
		--s; --t;
		to[s].push_back(t);
		from[t].push_back(s);
		h[t]++;
	}
	
	vector<int> toposort = topologicalSort(to,h);
	
	vector<int> dp(n), ans(n);
	rep(i,n){
		if(i == 0){
			ans[toposort[i]] = -1;
		}
		else{
			for(auto parent : from[toposort[i]]){
				if(dp[toposort[i]] < dp[parent] + 1){
					dp[toposort[i]] = dp[parent] + 1;
					ans[toposort[i]] = parent;
				}
			}
		}
	}
	
	rep(v,n) cout << ans[v]+1 << endl;
	return 0;
}
