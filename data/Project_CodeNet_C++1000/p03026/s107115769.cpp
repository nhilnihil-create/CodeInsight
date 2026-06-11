//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    vvi G(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vi c(n);
    rep(i, n) {
        cin >> c[i];
    }
    sort(all(c));

    vi si(n);
    queue<int> que;
    rep(i, n) {
        si[i] = G[i].size();
        if(si[i] == 1) {
            que.push(i);
        }
    }

    vi anv(n, -1);
    ll ans = accumulate(all(c), 0LL) - c[n-1];
    int nnow = 0;
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        anv[now] = c[nnow];
        ++nnow;
        if(nnow == n) break;
        if(G[G[now][0]].size() == 2) {
            que.push(G[now][0]);
        }
        vi::iterator itr = find(all(G[G[now][0]]), now);
        G[G[now][0]].erase(itr);
    }

    cout << ans << endl;
    rep(i, n) {
        cout << anv[i] << '\n';
    }
}