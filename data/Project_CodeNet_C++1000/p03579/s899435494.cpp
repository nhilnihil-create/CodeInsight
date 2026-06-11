#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
#include<functional>
#include<list>
#include<queue>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
typedef pair<ll, ll> p;
typedef vector<int> vec;
using Graph = vector<vector<int>>;
using graph = vector<vector<ll>>;


const ll inf = 1e9;
const long long MOD = 1000000007;

const int MAX_V = 1000000;

Graph G(MAX_V);       //グラフ
int V;                      //頂点数
int cnt = 0;

int color[MAX_V];           //頂点i（1or-1）

//頂点を１とー１で塗っていく
bool dfs(int v, int c) {
    color[v] = c;          //頂点vをcで塗る
    if (c == 1)cnt++;
    rep(i, G[v].size()) {
        //隣接している頂点が同じ色ならfalse
        if (color[G[v][i]] == c)return false;
        //隣接している頂点がまだ塗られていないなら-cを塗る
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c))return false;
    }
    //全ての頂点が塗れたらtrue
    return true;
}

void solve() {
    rep(i, V) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                cout << "No" << endl;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ll n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (dfs(1, 1))cout << cnt * (n - cnt) - m << endl;
    else cout << n * (n - 1) / 2 - m << endl;
    return 0;
}