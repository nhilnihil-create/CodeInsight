#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;

struct UnionFind {
    vector<ll> par, siz;

    UnionFind(ll N){
        for(ll i=0;i<N;++i){
            par.push_back(i);
            siz.push_back(1);
        }
    }

    ll root(ll x){
        while(x!=par[x]) x = par[x];
        return x;
    }

    bool same(ll x, ll y){
        return root(x) == root(y);
    }

    ll unite(ll x, ll y){
        ll xx = root(x);
        ll yy = root(y);
        ll ans;
        if(xx==yy) {
            ans = 0;
            return ans;
        }
        else {
            if(siz[xx] < siz[yy]) swap(xx, yy);
            ans = siz[xx] * siz[yy];
            par[yy] = xx;
            siz[xx] += siz[yy];
            return ans;
        }
    }
};

int main() {
    ll N, M;
    cin>>N>>M;
    UnionFind tree(N);
    ll ans = N*(N-1)/2;
    vector<ll> ansarr;
    ansarr.push_back(ans);
    ll A[M], B[M];
    for(ll i=0;i<M;++i){
        cin>>A[i]>>B[i];
        A[i]--;
        B[i]--;
    }
    ll tmpans;
    for(ll i=M-1;i>=0;--i){
        tmpans = tree.unite(A[i], B[i]);
        ans -= tmpans;
        ansarr.push_back(ans);
    }
    for(ll i=M-1;i>=0;--i){
        cout<<ansarr[i]<<endl;
    }
}

