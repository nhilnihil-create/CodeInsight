#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define F first
#define S second
#define int long long
using namespace std;

int n;
pair<int, int> a[200020];
vector<int> ed[200020];
map<int, int> mp;
int sz[200020];
int sum = 0;

void dfs(int now, int dept){
	sum += dept;
	rep(i, ed[now].size()){
		dfs(ed[now][i], dept+1);
	}
}

signed main(){
	cin >> n;
	rep(i, n){
		cin >> a[i].F;
		mp[a[i].F] = i;
		a[i].S = i;
	}
	rep(i, n) sz[i] = 1;
	sort(a, a+n);
	reverse(a, a+n);
	rep(i, n-1){
		int val = a[i].F;
		int to = a[i].F + 2*sz[a[i].S] - n;
		if(!mp.count(to)){
			cout << "-1" << endl;
			return 0;
		}
		int par = mp[to];
		sz[par] += sz[a[i].S];
		ed[par].push_back(a[i].S);
	}
	dfs(a[n-1].S, 0);
	if(sum != a[n-1].F){
		cout << "-1" << endl;
		return 0;
	}
	rep(i, n){
		rep(j, ed[i].size()){
			cout << i+1 << " " << ed[i][j]+1 << endl;
		}
	}
	return 0;
}