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
    ll N, K;
    cin >> N >> K;

    VVL s(N);
    rep(i, 0, N){
        ll t, d;
        cin >> t >> d;
        t--;
        s[t].push_back(d);
    }

    rep(i, 0, s.size()){
        sort(ALL(s[i]), greater<ll>());
        if(s[i].empty()) s[i].push_back(-(1LL<<40));
    }

    sort(s.begin(), s.end(), [&](VL a, VL b){return a[0] > b[0];});

    ll now = 0;
    priority_queue<ll> que;
    rep(i, 0, K){
        now += s[i][0];
        rep(j, 1, s[i].size()) que.push(s[i][j]);
    }

    rep(i, K, N){
        rep(j, 0, s[i].size()){
            que.push(s[i][j]);
        }
    }

    ll ans = now + K*K;
    for(ll x = K-1; x >= 1; x--){
        ll v = s[x][0];
        ll w = que.top();
        if(v < w){
            que.pop();
            now += w;
            now -= v;
            que.push(v);
        }
        ans = max(ans, now + x*x);
    }
    cout << ans << endl;
    return 0;
}