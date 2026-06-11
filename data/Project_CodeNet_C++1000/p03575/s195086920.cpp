#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


const ll MOD=1000000007ll;

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }

	void print(){
		for(int i=0;i<par.size();i++ ){
			cout<<par[i]<<" ";
		}
		cout<<endl;
	}
};


typedef vector<vector<int> > Graph;







int main(){
	

	int N,M;
	cin>>N>>M;


	vector<pair<int,int> > vecp(M);

	for(int i=0;i<M;i++){
		cin>>vecp[i].first>>vecp[i].second;	
		--vecp[i].first;
		--vecp[i].second;	
	}
    /*
	for(int i=0;i<M;i++){
		cout<<vecp[i].first<<":"<<vecp[i].second<<endl;
	}
	*/

	int count=0;

	for(int i=0;i<M;i++){
		UnionFind uf(N);
		for(int j=0;j<M;j++){
			if(i==j)continue;
			uf.merge(vecp[j].first,vecp[j].second);
		}
		//uf.print();
		if(!uf.issame(vecp[i].first,vecp[i].second)){
			++count;
		}
	}

     cout<<count<<endl;

}

