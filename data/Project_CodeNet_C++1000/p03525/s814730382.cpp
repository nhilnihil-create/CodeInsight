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
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int n;
bool used[103];
int cmp[103];
vector<int> g[103], gr[103];
vector<int> vs;
void init(){
	for(int i=0; i<2*n+2; i++) g[i].clear(), gr[i].clear();
}
void add(int x, int y){
	g[x].push_back(y); gr[y].push_back(x);
}
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
	fill(used, used+2*n+2, 0);
	vs.clear();
	for(int i=0; i<2*n+2; i++){
		if(!used[i]) dfs(i);
	}
	fill(used, used+2*n+2, 0);
	int k=0;
	for(int i=vs.size()-1; i>=0; i--){
		if(!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}
int main()
{
	cin>>n;
	int d[51]; d[0]=0;
	for(int i=1; i<=n; i++) cin>>d[i];
	for(int s=12; s>=0; s--){
		init();
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				if(i==j) continue;
				if(abs(d[i]-d[j])<s){
					add(i, j+n+1);
					add(i+n+1, j);
				}
				int x=abs((24-d[i])%24-d[j]);
				if(min(x, 24-x)<s){
					add(i, j);
					add(i+n+1, j+n+1);
				}
			}
		}
		scc();
		bool ok=1;
		for(int i=0; i<=n; i++){
			if(cmp[i]==cmp[i+n+1]){
				ok=0; break;
			}
		}
		if(ok){
			cout<<s<<endl;
			return 0;
		}
	}
	return 0;
}