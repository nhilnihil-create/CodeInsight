#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n){
    for(int i = 0; n > i; i++)par[i] = i;
  }

  int root(int n){
    if(par[n] == n)return n;
    return par[n] = root(par[n]);
  }

  void unite(int a,int b){
    int ra = root(a);
    int rb = root(b);
    if(ra==rb)return;
    par[ra] = rb;
  }

  bool same(int a, int b){
    return root(a) == root(b);
  }
};

int main(){
	int n,m;cin>>n>>m;
	vector<int> Z(n);
	UnionFind A(n);
	for(int i = 0; n > i; i++){
		cin>>Z[i];
	}
	for(int i = 0; m > i; i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		A.unite(x,y);
	}
	map<int,map<int,int> > B;
	for(int i = 0; n > i; i++){
		B[A.root(i)][i]++;
		B[A.root(i)][Z[i]-1]++;
	}
	int ans = 0;
	for(auto x:B){
		for(auto y:x.second){
			if(y.second==2)ans++;
		}
	}
	cout << ans << endl;
}
