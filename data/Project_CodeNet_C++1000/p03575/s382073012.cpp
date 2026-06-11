#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

vll prime_factrize(ll n){
    vll prime_factrize_ret;
    ll temp=n;
    for(ll i=2;i*i<=n;i++){
        while(temp%i==0){
            prime_factrize_ret.push_back(i);
            temp/=i;
        }
    }
    if(temp!=1) prime_factrize_ret.push_back(temp);
    return prime_factrize_ret;
}

ll fast_pow(ll n,ll a,ll mod){
    ll res=1;
    while(a>0){
        if(a&1) res=res*n%mod;
        n=n*n%mod;
        a>>=1;
    }
    return res;
}

ll mod_inv(ll n, ll mod){
    return fast_pow(n,mod-2,mod);
}

ll comb(ll n, ll r, ll mod){
    ll temp=1;
    for(int i=r+1;i<=n;i++){
        temp=(temp*i)%mod;
    }
    ll temp2=1;
    for(int i=2;i<=n-r;i++){
        temp2=(temp2*i)%mod;
    }
    return temp*mod_inv(temp2,mod)%mod;
}

struct UnionFind {
    vector<int> r;
 
    UnionFind(int N) {
        r = vector<int>(N, -1);
    }
 
    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }
 
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    bool same(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return true;
        else return false;
    }
 
    int size(int x) {
        return -r[root(x)];
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    vi a(m);
    vi b(m);
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    int ans=0;
    for(int i=0;i<m;i++){
        UnionFind uf(n);
        for(int j=0;j<m;j++){
            if(j==i) continue;
            uf.unite(a[j],b[j]);
        }
        if(uf.size(0)!=n) ans++;
    }
    cout << ans << endl;
}