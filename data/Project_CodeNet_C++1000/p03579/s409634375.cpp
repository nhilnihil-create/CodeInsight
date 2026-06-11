#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool dfs(int key, vector<vector<int>> &v, vector<int> &w){
    bool flag=true;
    for(int i=0; i<v[key].size(); ++i){
        if(w[v[key][i]]<0){
            w[v[key][i]]=1-w[key];
            flag=flag&&dfs(v[key][i], v, w);
        }else{
            flag=flag&&(w[key]!=w[v[key][i]]);
        }
    }
    return flag;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> g(N+1);
    for(ll i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> bw(N+1, -1);
    bw[1]=0;
    if(dfs(1, g, bw)){
        ll W=0;
        for(ll i=1; i<=N; ++i) W += bw[i];
        cout << W*(N-W)-M << endl;
    }else{
        cout << N*(N-1)/2-M << endl;
    }
    return 0;
}
