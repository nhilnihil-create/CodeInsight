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
#define INF 1000000000
#define MAX 200001
#define PI 3.141592653589793

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int par[1000000];
void init(int N){
    rep(i,N) par[i] = -1;
}

int find(int a){
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

int size(int A) {
     return -par[find(A)];
}

bool same(int a, int b){
    return find(a) == find(b);
}

int main(){
    int N, M;
    cin >> N >> M;
    int ans = 0;
    init(N);
    vector<int> p(N);
    rep(i,N) cin >> p[i];
    rep(i,M){
        int x,y;
        cin >> x >> y;
        x--;y--;
        unite(x,y);
    }
    vector<int> q(N);
    map<int, vector<int>> m;
    rep(i,N){
        q[i] = find(i);
        m[q[i]].push_back(p[i]);
    }
    rep(i,N){
        if(find(m[q[i]].begin(), m[q[i]].end(),i+1) != m[q[i]].end()) ans++;
    }
    cout << ans << endl;
}