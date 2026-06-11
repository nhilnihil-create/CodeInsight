#include <bits/stdc++.h>
using namespace std;
/* kmjpさん */

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;

int n, m;
set<int> e[100010];
set<int> re[100010];
int ans[100010];

int main(){
    cin >> n >> m;
    REP(i, n+m-1) {
        int a, b;
        cin >> a >> b;
        e[a].insert(b);
        re[b].insert(a);
    }

    /* 入次数が0の頂点を探す */
    REPN(i, 1, n+1) if(re[i].empty()) {
        e[0].insert(i);
        re[i].insert(0);
        break;
    }

    /* トポロジカルソート */
    queue<int> Q;
    Q.push(0);
    while(Q.size()) {
        int x = Q.front();
        Q.pop();
        for(auto y: e[x]) {
            /* つながっている先を見て、つぶしていく */
            re[y].erase(x);
            /* 最後のやつは、一番近いやつのはず */
            if(re[y].empty()) {
                ans[y] = x;
                Q.push(y);
            }
        }
    }

    REPN(i, 1, n+1) cout << ans[i] << endl;
    return 0;
}
