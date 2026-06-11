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
    vector<int> a(m,0),b(m,0);
    for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
		a[i]--; b[i]--;
	}
    vector<ll> ans(m);
    struct union_find U(n);
    for(int i=m-1;i>=0;i--){
		if(!U.same(a[i],b[i])){
			ans[i]=U.Size[U.root(a[i])]*U.Size[U.root(b[i])];
		}
		//cout<<"a.size="<<U.Size[a[i]]<<" , b.size="<<U.Size[b[i]]<<endl;
		U.unite(a[i],b[i]);
    }
    for(int i=0;i<m;i++){
		cout<<ans[i]<<endl;
		if(i<m-1) ans[i+1]+=ans[i];
	}
    return 0;
}