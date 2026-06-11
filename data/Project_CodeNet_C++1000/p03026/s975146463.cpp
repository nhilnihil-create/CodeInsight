#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	
	
	vector<vector<int>> to(n);
	rep(i,n-1){
		int a,b;
		cin >> a >> b;
		--a; --b;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	
	priority_queue<int> c;
	rep(i,n){
		int tmp;
		cin >> tmp;
		c.push(tmp);
	}
	
	vector<int> d(n,-1);

	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		d[now] = c.top();
		c.pop();
		for(auto v : to[now]){
			if(d[v] == -1) q.push(v);
		}
	}
	
	ll m = -d[0];
	rep(i,n) m += d[i];
	cout << m << endl;
	
	rep(i,n){
		cout << d[i] << " ";
	}
	
	return 0;
}