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
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;

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
    ll n,m;
    cin>>n>>m;
    struct union_find U(n);
    while(m){
        ll a,b,z;
        cin>>a>>b>>z;
        a--; b--;
        U.unite(a,b);
        m--;
    }
    ll ans=0;
    vector<bool> f(n,true);
    for(int i=0;i<n;i++){
        if(f[U.root(i)]){
            ans++;
            f[U.root(i)]=false;
        }
    }
    cout<<ans<<endl;
    
}