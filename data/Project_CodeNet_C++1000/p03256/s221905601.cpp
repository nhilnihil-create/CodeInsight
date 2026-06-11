#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int n, m;
bool used[400001];
int cmp[400001];
vector<int> g[400001], gr[400001];
vector<int> vs;
string s;

void dfs(int x){
	used[x]=1;
	for(auto y:g[x]){
		if(!used[y]) dfs(y);
	}
	vs.push_back(x);
}

void rdfs(int v, int k){
	used[v]=1;
	cmp[v]=k;
	for(auto y:gr[v]){
		if(!used[y]) rdfs(y, k);
	}
}

int scc(){
	fill(used, used+2*n, 0);
	vs.clear();
	for(int i=0; i<2*n; i++){
		if(!used[i]) dfs(i);
	}
	fill(used, used+2*n, 0);
	int k=0;
	for(int i=vs.size()-1; i>=0; i--){
		if(!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

int main()
{
	cin>>n>>m;
	cin>>s;
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		a--; b--;
		if(s[a]==s[b]){
			g[a].push_back(b+n);
			g[b].push_back(a+n);
			gr[a+n].push_back(b);
			gr[b+n].push_back(a);
		}else{
			g[a+n].push_back(b);
			g[b+n].push_back(a);
			gr[a].push_back(b+n);
			gr[b].push_back(a+n);
		}
	}
  int k=scc();
	if(k<2*n) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}