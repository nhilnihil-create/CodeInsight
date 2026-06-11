#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> field(h);
    rep(i,h) cin >> field[i];

    queue<int> queh;
    queue<int> quew;
    vvi dist(h, vi(w, -1));
    vvi res(h, vi(w, -1));
    vi dh = {0, -1, 0, 1};
    vi dw = {1, 0, -1, 0};

    rep(i,h)rep(j,w){
        if (field[i][j] == '#'){
            queh.push(i); quew.push(j);
            dist[i][j] = 0;
        }
    }
     while (!queh.empty() && !quew.empty()){
        int i = queh.front(); queh.pop();
        int j = quew.front(); quew.pop();
        rep(k,4){
            int ni = i + dh[k];
            int nj = j + dw[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >=w) continue;
            if (dist[ni][nj] != -1) continue;
            if (field[ni][nj] == '#') continue;
            queh.push(ni);
            quew.push(nj);
            dist[ni][nj] = dist[i][j] + 1;
        }
    }

    int ans = 0;
    rep(i,h)rep(j,w){
        ans = max(ans, dist[i][j]);
    }
    cout << ans << endl;
    return 0;
}
