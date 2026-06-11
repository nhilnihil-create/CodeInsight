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

int main(){
    ll N;
    cin >> N;
    VVL G(N);
    rep(i, 0, N-1){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    VL c(N), d(N);
    rep(i, 0, N) cin >> c[i];
    sort(ALL(c), greater<ll>());
    ll ans = 0, ptr = 1;
    queue<ll> que;
    que.push(0);
    d[0] = c[0];
    VB seen(N, false);
    while(!que.empty()){
        auto q = que.front();
        que.pop();
        if(seen[q]) continue;
        seen[q] = true;
        for(auto g : G[q]){
            if(seen[g]) continue;
            d[g] = c[ptr];
            ptr++;
            que.push(g);
            ans += min(d[g], d[q]);
        }
    }
    cout << ans << endl;
    rep(i, 0, N){
        cout << d[i];
        if(i == N-1) cout << endl;
        else cout << " ";
    }
    return 0;
}