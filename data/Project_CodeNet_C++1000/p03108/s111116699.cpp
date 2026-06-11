#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

class UnionFind {
public:
    vector <LL> par;
    vector <LL> siz;

    UnionFind(LL sz_): par(sz_), siz(sz_, 1LL) {
        for (LL i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(LL sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (LL i = 0; i < sz_; ++i) par[i] = i;
    }

    LL root(LL x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }

    bool unite(LL x, LL y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool same(LL x, LL y) {
        return root(x) == root(y);
    }

    LL size(LL x) {
        return siz[root(x)];
    }
};

int main(){
	LL N, M;
	cin >> N >> M;
	UnionFind uf(N);
	LL num=N*(N-1)/2;
	vector<P> p(M);
	rep(i,M){
		int A, B;
		cin >> A >> B;
		A--; B--;
		p[i]={A,B};
	}
	reverse(p.begin(),p.end());
	vector<LL> ans(M);
	rep(i,M){
		ans[i]=num;
		int A=p[i].first, B=p[i].second;
		if(!uf.same(A,B)){
			num-=uf.size(A)*uf.size(B);
			uf.unite(A,B);
		}
	}
	reverse(ans.begin(),ans.end());
	rep(i,M) cout << ans[i] << endl;

	return 0;
}