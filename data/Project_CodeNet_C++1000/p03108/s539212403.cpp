#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
ll sz(string &s){ return (ll)s.size(); }
ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }


struct unionfind {
    vector<int> par;
    vector<int> sizes;

    unionfind(int n) : par(n),sizes(n,1){
        rep(i,0,n) par[i] = i;
    }

    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x,int y){
        x = root(x);
        y = root(y);

        if(x == y) return;

        if(sizes[x] < sizes[y] ) swap(x,y);

        par[y] = x;
        sizes[x] += sizes[y];
        sizes[y] = 0;

        return;
    }

    bool same(int x,int y){
        return root(x) == root(y);
    }

    int size(int x){
        return sizes[root(x)];
    }
};


int main(){
    ll n,m;
    cin >> n >> m;

    unionfind uf(n);
    ll a[m],b[m];
    vector<ll> ans;

    rep(i,0,m){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }

    ll temp = n*(n-1)/2;
    ans.push_back(temp);

    rep(i,0,m){
        if(!uf.same(a[m-i-1],b[m-i-1])){
            temp -= uf.size(a[m-i-1])*uf.size(b[m-i-1]);     
        }
        ans.push_back(temp);
        uf.unite(a[m-i-1],b[m-i-1]);
    }


    
    rep(i,1,sz(ans)){
        cout << ans[sz(ans)-1-i] << endl;
    }
    

    return 0;
}
