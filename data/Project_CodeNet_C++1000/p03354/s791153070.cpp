#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int  mx = 100005;
vector<int> p;
vector<int> e[mx];
int visited[mx] ={0};
void rec(vector<int> *pos,vector<int> *val,int cur) {
    visited[cur] = 1;
    pos->push_back(cur); val->push_back(p[cur]);
    for(int u : e[cur]) {
        if(visited[u]) continue;
        rec(pos,val,u);
    }
}
int main() {
    int ans = 0;
    int n, m; cin >> n >> m;
    p.resize(n+1);
    rep(i, n) cin >> p[i+1];
    rep(i, m) {
        int x, y; cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++) {
        if(visited[i]) continue;
        vector<int> pos;
        vector<int> val;
        rec(&pos,&val,i);
        int y = pos.size();
        //printf("y:%d\n",y);
        sort(pos.begin(), pos.end()); sort(val.begin(), val.end());
        while(!pos.empty()||!val.empty()) {
            int pp = pos.back(); int vv = val.back();
            if(pp < vv) val.pop_back();
            else if(pp == vv) {
                pos.pop_back(); val.pop_back();
                ans++;
            }else{
                pos.pop_back();
            }
        }
    }
    cout << ans;
}
