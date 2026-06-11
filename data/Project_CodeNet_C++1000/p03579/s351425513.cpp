#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> g[100010];
int res[100010];
vector<int> C(100010);
int n,m;

void dfs(int v,int c){
  if(C[v]==-1){
    C[v]=c;
    res[c]++;
    for(auto e:g[v]) dfs(e,c^1);
  }else	if(C[v]!=-1) {
		if(C[v]!=c) {
			cout<<1LL*n*(n-1)/2-m<<endl;
			exit(0);
		}
	}
}

int main(){
  cin >>n>>m;
  fill(C.begin(),C.end(),-1);
  rep(i,m){
    int a,b;
    cin >> a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0,0);
  cout<<1LL*res[0]*res[1]-m<<endl;
}