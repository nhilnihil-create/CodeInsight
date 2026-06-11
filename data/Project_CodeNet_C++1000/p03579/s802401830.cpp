#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

vector<int> G[100100];
int C[100100];
ll X[2];

bool dfs(int v, int c){
    C[v] = c;
    X[(c+1)/2]++;
    for(int i = 0; i < G[v].size(); i++){
        int next = G[v][i];
        bool valid = true;
        if(C[next] == 0){
            valid = dfs(next, -c);
        }
        else if(C[next] == c){
            valid = false;
        }
        if(!valid) return false;
    }

    return true;
}

int main(){
    ll N, M;
    cin >> N >> M;
    REP(i,M){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool two = dfs(0, -1);
    ll ans = 0;
    if(two){
        ans = X[0]*X[1] - M;
    }
    else{
        ans = N*(N-1)/2 - M;
    }

    cout << ans << endl;
    return 0;
}
