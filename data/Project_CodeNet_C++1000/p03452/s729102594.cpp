#include <iostream>
#include <cmath>
#define ll long long int

using namespace std;

int par[100001];
int r[100001];
ll weight[100001];
int n, m;

void init(){
		for(int i = 0; i < n; i++)par[i] = i;
}

int find(int x){
		if(par[x] == x)return x;
		else {
				int parent = find(par[x]);
				weight[x] += weight[par[x]];
				return par[x] = parent;
		}
}

bool same(int x, int y){
		return find(x) == find(y);
}

// x: left y: right
bool unite(int x, int y, ll w){
		int xp = find(x);
		int yp = find(y);
		w = w - weight[y] + weight[x];
		if(xp == yp){
				if(weight[yp] - weight[xp] == w)return true;
				else return false;
		}
		if(r[xp] > r[yp]){
				par[yp] = xp;
				weight[yp] = w;
		}else{
				par[xp] = yp;
				weight[xp] = -w;
				r[yp]++;
		}
		return true;
}

int main(int argc, char const* argv[])
{
	cin >> n >> m;
	init();
	for(int i = 0; i < m; i++){
			int l, r, d;
			cin >> l >> r >> d;
			l--;
			r--;
			if(!unite(l, r, d)){
					cout << "No" << endl;
					return 0;
			}
	}
	for(int i = 0; i < n; i++){

	}
	cout << "Yes" << endl;
	return 0;
}
