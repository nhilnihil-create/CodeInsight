#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

ll h, w;
VS s;

int main(){
    cin >> h >> w;
    s.resize(h);
    rep(i, 0, h) cin >> s[i];
    ll num = 0;
    rep(i, 0, h) {
        rep(j, 0, w){
            if(s[i][j] == '.') num++;
        }
    }
    num -= 2;
    vector<vector<ll>> d(h, vector<ll>(w,1e18));
    /* dijkstra's scope */{
        typedef pair<ll, pair<ll,ll>> pl;
        priority_queue<pl, vector<pl>, greater<pl>> que;
        que.push({0, {0, 0}});
        d[0][0] = 0;
        while(!que.empty()){
            auto q = que.top();
            que.pop();
            auto i = q.second.first;
            auto j = q.second.second;
            if(q.first > d[i][j]) continue;
            rep(g, 0, 4){
                auto ni = i + d1[g];
                auto nj = j + d2[g];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(s[ni][nj] == '#') continue;
                if(d[ni][nj] <= q.first + 1) continue;
                d[ni][nj] = q.first + 1;
                que.push({d[ni][nj], {ni, nj}});
            }
        }
    }
    if(d[h-1][w-1] != 1e18) cout << num - d[h-1][w-1] + 1 << endl;
    else cout << -1 << endl;
    return 0;
}