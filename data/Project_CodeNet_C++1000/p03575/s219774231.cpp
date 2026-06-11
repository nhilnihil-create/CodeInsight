//q086.cpp
//Sun Sep  6 16:35:59 2020

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

int par[60]; //親。1個上の親でしか無いことに注意。グループの根はfindで呼び出す。
int treerank[60]; //木の深さ

//n要素で初期化
void init(int n){
	for (int i=0;i<n;i++){
		par[i] = i;
		treerank[i] = 0;
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

	if (treerank[x] < treerank[y]){
		par[x] = y;
	} else {
		par[y] = x;
		if (treerank[x] == treerank[y]){
			treerank[x]++;
		}
	}
}

//xとyが同じグループに属するか判定
bool same(int x, int y){
	return find(x) == find(y);
}

int main(){
	int n,m;
	cin >> n >> m;

	vector<int> a(m,0);
	vector<int> b(m,0);
	rep(i,m){
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
	} 

	int count = 0;
	int ans = 0;
	while(count<m){
		init(n);
		rep(i,m){
			if(i==count)continue;
			unite(a[i],b[i]);
		}
		set<int> st;
		rep(i,n){
			st.insert(find(i));
		}
		if (st.size()!=1){
			ans++;
		}
		count++;
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}