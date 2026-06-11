#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX_N 100000

ll n;
int m;
vector<int> G[MAX_N];
int color[MAX_N];

bool dfs(int v, int c){
    color[v] = c;
    for(auto u : G[v]){
        if(color[u] == c) return false;
        if(color[u] == 0 && !dfs(u, -c)){
            return false;
        }
    }
    return true;
}

signed main(){
    cin >> n >> m;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    if(!dfs(0, 1)){
        cout << n * (n - 1) / 2 - m << endl;
    }else{
        ll black = 0, white = 0;
        for(int v = 0; v < n; v++){
            if(color[v] == 1) black++;
            else white++;
        }
        cout << black * white - m << endl;
    }
    return 0;
}