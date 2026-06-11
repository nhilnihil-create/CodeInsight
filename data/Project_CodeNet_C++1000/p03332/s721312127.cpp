#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MM 1000000000
#define MOD MM+7
#define MAX 301000
#define MAP 110
#define initial_value -1
#define Pair pair<int,int>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
ll INF = 1e18;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int depth[100100];
int par[100100];

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n,-1) {}
    void init(int n) { par.assign(n,-1);}
    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x){
        return -par[root(x)];
    }
};
ll N,A,B,K; ll TMP = 998244353;
ll fac[550000], finv[550000], inv[550000];
void Combination_init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < 550000; i++){
        fac[i] = (fac[i-1]*i) % TMP;
        inv[i] = TMP - inv[TMP%i] * (TMP/i) % TMP;
        finv[i] = (finv[i-1] * inv[i]) % TMP;
    }
}
ll COM(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%TMP)%TMP;
}

int main(){
    Combination_init();
    cin >> N >> A >> B >> K;
    ll res = 0;
    for(ll a = 0; a <= N; a++){
        ll rem = K - a*A;
        if(rem % B != 0) continue;
        ll b = rem/B;
        if(b > N) continue;
        ll tmp = COM(N,a)*COM(N,b)%TMP;
        res += tmp;
        res %= TMP;
    }
    cout << res << endl;
}
