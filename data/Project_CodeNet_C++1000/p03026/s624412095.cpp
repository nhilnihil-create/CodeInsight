#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define MAX 10000

int n;
pair<int, int> d[MAX];
vector<int> e[MAX];
int c[MAX], w[MAX], k;

void dfs(int s){
	w[s]=c[k];
	k++;
	for(int i=0; i<e[s].size(); i++){
		if(w[e[s][i]]==0){
			dfs(e[s][i]);
		}
	}
	return;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		d[i].first=0;
		d[i].second=i;
	}
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
		d[a].first++;
		d[b].first++;
	}
	for(int i=0; i<n; i++) cin >> c[i];
	sort(d, d+n, greater<pair<int, int>>());
	sort(c, c+n, greater<int>());

	for(int i=0; i<n; i++){
		if(w[i]==0){
			dfs(i);
		}
	}

	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<e[i].size(); j++){
			ans+=min(w[i], w[e[i][j]]);
		}
	}
	cout << ans/2 << endl;
	for(int i=0; i<n; i++) cout << w[i] << " ";
	cout << endl;
	return 0;
}