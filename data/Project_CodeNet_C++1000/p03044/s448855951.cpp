#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<pair<int, int> > to[100005];
vector<int> color(100005, 0);

void dfs(int n, int b, int c){
    rep(i, to[n].size()){
        int a = to[n][i].first;
        if(a == b)continue;
        int x = to[n][i].second;
        int cc;
        if(x % 2 == 1){
            cc = (c+1)%2;
        } else {
            cc = c;
        }
        color[a] = cc;
        dfs(a, n, cc);
    }
    return;
}

int main() {
    int N; cin >> N;
    //to.resize(N);
    //color.resize(N);

    rep(i, N-1){
        int u, v, w; cin >> u >> v >> w;
        u--;
        v--;
        to[u].push_back(make_pair(v, w));
        to[v].push_back(make_pair(u, w));
    }

    dfs(0, -1, 0);

    rep(i, N){
        cout << color[i] << endl;
    }


    return 0;
}