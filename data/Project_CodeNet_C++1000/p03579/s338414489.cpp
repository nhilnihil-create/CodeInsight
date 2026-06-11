#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

ll N, M, num[] = {0, 0};
vector<int> edge[100000];
int col[100000];
bool res = true;

void dfs(int now){
    int c = col[now];
    num[c]++;
    for(auto &e: edge[now]){
        if(col[e] == -1){
            col[e] = (c+1)%2;
            dfs(e);
        }
        elif(col[e] == c){
            res = false;
        }
    }
}

int main(){
    cin >> N >> M;
    rep(i, M){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edge[u].pb(v), edge[v].pb(u);
    }
    fill_n(col, 100000, -1);
    col[0] = 0;
    dfs(0);
    if(!res){
        cout << N*(N-1)/2 - M << endl;
    }
    else{
        cout << num[0]*num[1]-M << endl;
    }
}