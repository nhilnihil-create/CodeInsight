#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, C; cin >> N >> C;
    vector<ii> tv[C+1];
    FOR(i,0,N-1){
        int s, t, c; cin >> s >> t >> c;
        tv[c].emplace_back(s,t);
    }

    vector<ii> inv;
    FOR(c,1,C) if (!tv[c].empty()) {
        sort(ALL(tv[c]));
        ii cur = ii(tv[c][0].fi, tv[c][0].fi);
        for (auto& x : tv[c]) {
            if (cur.sc == x.fi) cur.sc = x.sc;
            else inv.push_back(cur), cur = x;
        }
        inv.push_back(cur);
    }

    sort(ALL(inv));
    priority_queue<int,vector<int>,greater<int> > pq;
    for (auto& x : inv) {
        if (!pq.empty() && pq.top() < x.fi) pq.pop();
        pq.push(x.sc);
    }

    cout << SZ(pq);
}

