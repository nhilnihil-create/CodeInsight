#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

bool seen[60];
vvi G(60);

void dfs(int v){
    seen[v] = true;
    for (auto nv : G[v]){
        if (seen[nv]) continue;
        dfs(nv);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vec(60);

    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        vec[i].first = a;
        vec[i].second = b;
    }

    int ans = 0;
    rep(i,m){
        memset(seen, 0, sizeof(seen));

        int a, b;
        a = vec[i].first; b = vec[i].second;
        for (auto &ele : G[a]){
            if (ele == b) ele = a;
        }
        for (auto &ele : G[b]){
            if (ele == a) ele = b;
        }

        int cnt = 0;
        rep(j,n){
            if (seen[j]) continue;
            dfs(j);
            cnt++;
        }
        if (cnt > 1) ans++;

        for (auto &ele : G[a]){
            if (ele == a) ele = b;
        }
        for (auto &ele : G[b]){
            if (ele == b) ele = a;
        }
    }
    
    cout << ans << endl;
    return 0;
}
