//q087.cpp
//Sun Sep  6 17:01:43 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

//Union-Find木
int par[1000000]; //親。1個上の親でしか無いことに注意。グループの根はfindで呼び出す。
int treesize[1000000]; //木のサイズ

//n要素で初期化
void init(int n){
	for (int i=0;i<n;i++){
		par[i] = i;
		treesize[i] = 1;
	}
}

//木の根（親）を見つける。再帰することで、グループの根まで辿る。
int find (int x){
	if (par[x] == x){
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}

//xとyの属する集合の併合
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	} 
	if (treesize[x]>treesize[y]){
		par[y] = x;
		treesize[x] += treesize[y];
	}else{
		par[x] = y;
		treesize[y] += treesize[x];
	}
}

//xとyが同じグループに属するか判定
bool same(int x, int y){
	return find(x) == find(y);
}


int main(){
	ll n,m;
	cin >> n >> m;

	vector<ll> a(m,0);
	vector<ll> b(m,0);
	rep(i,m) cin >> a[i] >> b[i];

	init(n);

	vector<ll> ans(m,0);
	ll cur = n*(n-1)/2;
	for(ll i=m-1;i>=0;i--){
		ans[i]=cur;
		if (!same(a[i],b[i])){
			cur -= treesize[find(a[i])]*treesize[find(b[i])];
		}
		unite(a[i],b[i]);
	}

	rep(i,m){
		cout << ans[i] << endl;
	}
//	printf("%.4f\n",ans);
}