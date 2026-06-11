#include <bits/stdc++.h>

using namespace std;

struct node{
	vector<int> cld;
	bool vis;
	int as;
	node(){
		vis = 0;
		as = 0;
	}
}a[100005];

void dfs(int n){
	if(a[n].vis) return;
	a[n].vis = 1;
	for(int i : a[n].cld){
		dfs(i);
		a[n].as = max(a[n].as , a[i].as + 1);
	}
}

int main(){
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		int aa , b;
		cin>>aa>>b;
		aa-- , b--;
		a[aa].cld.push_back(b);
	}
	for(int i = 0 ; i < n ; i++){
		dfs(i);
	}
	int ans = 0;
	for(int i = 0 ; i < n ; i++) ans = max(ans , a[i].as);
	cout<<ans<<endl;
}