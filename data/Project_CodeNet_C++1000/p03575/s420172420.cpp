#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

struct union_find{
  vector<int> par,r;

  union_find(int n){
  	par.resize(n);
  	r.resize(n);
  	init(n);
  }

  void init(int n){
    for(int i = 0; i < n; i++) par[i] = i;
    for(int i = 0; i < n; i++) r[i] = 0;
  }

  int find(int x){
    if(par[x] == x) return x;
    else return find(par[x]);
  }

  void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(r[x] < r[y]){
      par[x] = y;
    }else{
      par[y] = x;
      if(r[x] == r[y]) r[x]++;
    }
  }

  bool same(int x,int y){
  	return find(x) == find(y);
  }
};

int main()
{
	int n,m;
	cin >> n >> m;

	vector<pair<int,int> > e(m);

	for(int i = 0; i < m; i++){
		cin >> e[i].first >> e[i].second;
		e[i].first--;
		e[i].second--;
	}

	int ans = 0;
	for(int i = 0; i < m; i++){
		union_find uf(n);

		for(int j = 0; j < m; j++){
			if(i!=j && !uf.same(e[j].first,e[j].second)){
				uf.unite(e[j].first,e[j].second);
			}
		}
		set<int> s;
		for(int j = 0; j < n; j++){
			if(uf.par[j]==j) s.insert(uf.par[j]);
		}
		if(s.size()>1) ans++;
	}

	cout << ans << endl;

	return 0;
}