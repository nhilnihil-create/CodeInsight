#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;

class UnionFind
{
private:
    vector<ll> p;
    vector<ll> rank;
public:
    UnionFind(ll n){
        p.resize(n,-1);
        rank.resize(n,1);
    }
    ll find(ll x){
        if(p[x]<0)return x;
        return p[x]=find(p[x]);
    }
    void unite(ll x,ll y){
        x=find(x);
        y=find(y);
		if(x==y)return;
        if(rank[x]>rank[y])swap(x,y);
        if(rank[x]==rank[y])rank[y]++;
        p[y]+=p[x];
        p[x]=y;
    }
    ll size(ll x){
        return -p[find(x)];
    }
	bool same(ll a, ll b){
		return find(a) == find(b);
	}
};

signed main(){
	//cout << fixed << setprecision(10);
	ll n,m; cin >> n >> m;
	UnionFind uf(n);
	vl ans(m);
	vector<pl> vec(m);
	rep(i,0,m){
		cin >> vec[i].first >> vec[i].second;
		vec[i].first--;
		vec[i].second--;
	}
	ll ret = 0;
	for(int i = m - 1; i >= 0; i--){
		ans[i] = n * (n - 1) / 2  - ret;
		if(!uf.same(vec[i].first , vec[i].second)){
			ret += uf.size(vec[i].first) * uf.size(vec[i].second);
			uf.unite(vec[i].first , vec[i].second);
		}
	}
	rep(i,0,m)cout << ans[i] << endl;
}
