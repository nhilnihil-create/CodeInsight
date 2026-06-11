#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int N, M;
vi G[101010];
int used[101010] = {};
map<int,int> mp;
map<pii,int> d;

bool dfs(int n) {
    bool ret = 1;
    used[n] = 1;
    for (int v : G[n]) {
        if (used[v]) {
            //cout << n << " " << v << " " << d[pii(n, v)] << endl;
            if (mp[v] != mp[n] + d[pii(n, v)]) return 0;
            continue;
        }
        mp[v] = mp[n] + d[pii(n, v)];
        if (!dfs(v)) return 0;
    }
    return ret;
}

void solve() {
    cin >> N >> M;
    vector<vi> info(M);
    rep(i,M) {
        int l, r, dd;
        cin >> l >> r >> dd;
        info[i] = vi({l, r, dd});
        l--; r--;
        G[l].push_back(r);
        G[r].push_back(l);
        d[pii(l, r)] = dd;
        d[pii(r, l)] = -dd;
    }
    sort(info.begin(), info.end());
    rep(i,N) {
        if (used[i]) continue;
        mp[i] = 0;
        int res = dfs(i);
        if (!res) {
            cout << "No" << endl;
            return;
        }
    }
    // REP(i,0,M) {
    //     if (!mp.count(info[i][0]) && !mp.count(info[i][1])) {
    //         mp[info[i][0]] = 0;
    //         mp[info[i][1]] = info[i][2];
    //     } else if (mp.count(info[i][0]) && mp.count(info[i][1])) {
    //         if (mp[info[i][0]] + info[i][2] != mp[info[i][1]]) {
    //             cout << "No" << endl;
    //             return;
    //         }
    //     } else if (mp.count(info[i][0])) {
    //         mp[info[i][1]] = mp[info[i][0]] + info[i][2];
    //     } else if (mp.count(info[i][1])) {
    //         mp[info[i][0]] = mp[info[i][1]] - info[i][2];
    //     }
    // }
    cout << "Yes" << endl;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    solve();
    return 0;
}
