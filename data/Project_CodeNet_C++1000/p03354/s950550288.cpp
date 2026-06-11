#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}


const int MAXN=100001;
int a[MAXN];
int par[MAXN], rnk[MAXN];

void init(int n){
	REP(i,n){
		par[i] = i;
		rnk[i] = 0;
	}
}
int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(rnk[x] < rnk[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rnk[x]==rnk[y]) rnk[x]++;
	}
}
bool same(int x,int y){
	return find(x)==find(y);
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> p(n+1,0);
	REP(i,n) cin >> p[i+1];
	
	init(MAXN);
	REP(i,m){
		int x,y;
		cin >> x >> y;
		a[x] = 1;
		a[y] = 1;
		unite(x,y);
	}
	
	int ans = 0;
	FOR(i,1,n+1){
		if(a[i]!=0){
			if(same(i, p[i])) ans++;
		}else{
			if(i==p[i]) ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}