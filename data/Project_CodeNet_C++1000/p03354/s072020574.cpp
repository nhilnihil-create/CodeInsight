#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

struct union_find {
	ll par[MAX_N];
	ll Size[MAX_N];
	union_find(ll n) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
			Size[i] = 1;
		}
	}
	ll root(ll x) {
		if (par[x] == x)return x;
		return par[x] = root(par[x]);
	}
	bool same(ll x, ll y) {
		return root(x) == root(y);
	}
	void unite(ll x, ll y) {
		if (same(x, y))return;
		Size[root(x)] += Size[root(y)];
		par[root(y)] = root(x);
	}
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
    }
    int x,y;
    struct union_find U(n);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        U.unite(x,y);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(U.same(i,p[i])) ans++;
    }
    cout<<ans<<endl;
}