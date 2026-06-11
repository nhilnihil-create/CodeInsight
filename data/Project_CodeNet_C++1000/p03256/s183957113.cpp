#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N, M;
string S;
vector<int> G[400010];
bool came[400010];
bool finish[400010];
bool flag;

void dfs(int v){
    came[v] = true;
    for(auto u : G[v]){
        if(came[u]){
            if(!finish[u]) flag = true;
        }else{
            dfs(u);
        }
    }
    finish[v] = true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> S;
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(S[a] == S[b]){
            G[N + a].push_back(b);
            G[N + b].push_back(a);
        }else{
            G[a].push_back(N + b);
            G[b].push_back(N + a);
        }
    }
    for(int i = 0; i < 2 * N; ++i){
        if(!finish[i]) dfs(i);
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}