#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

ll par[1000000];

void init(ll N){
    rep(i,N) par[i] = -1;
}

ll find(int a){
    if(par[a] < 0) return a;
    else{
        return par[a] = find(par[a]);
    }
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    else{
        if(par[a] > par[b]) swap(a,b);
        par[a] += par[b];
        par[b] = a;
    }
}

ll size(int A) {
    return -par[find(A)];
}

bool same(int a, int b){
    return find(a) == find(b);
}

int main(){
    ll N,M;
    cin >> N >> M;
    vector<pair<int,int>> edges(M);
    rep(i,M){
        int a, b;
        cin >> a >> b;
        a--;b--;
        edges[i] = {a,b};
    }
    ll ans = N*(N-1)/2;
    vector<ll> ANS(M);
    ANS[M-1] = ans;
    init(N);
    for(int i = M-1; i > 0; i--){
        int a = edges[i].first;
        int b = edges[i].second;
        if(!same(a,b)) ans -= size(a)*size(b);
        unite(a,b);
        ANS[i-1] = ans;
    }
    rep(i,M) cout << ANS[i] << endl;
}