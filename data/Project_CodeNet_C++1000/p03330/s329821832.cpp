#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll N, C; cin >> N >> C;
    vvi D(C, vi(C, 0)), G(N, vi(N, 0)), M(3, vi(0));
    rep(i, C) rep(j, C) cin >> D[i][j];
    rep(i, N) rep(j, N){ cin >> G[i][j]; G[i][j]--; }

    // 3の剰余算でグループ分け
    rep(i, N) rep(j, N) M[(i+j)%3].push_back(G[i][j]);

    // グループごとに全探索
    vector<vector<pair<ll, ll>>> Discomf(3, vector<pair<ll, ll>>(C));
    rep(i, 3) rep(j, C){
        ll cnt = 0;
        for(auto Pre: M[i]) cnt += D[Pre][j];
        Discomf[i][j] = make_pair(cnt, j);
    }

    ll ans = INFLL;
    rep(i, C){
        rep(j, C){
            if(i == j) continue;
            rep(k, C){
                if(i == k || j == k) continue;
                chmin(ans, Discomf[0][i].first + Discomf[1][j].first + Discomf[2][k].first);
            }
        }
    }
    cout << ans << endl;
}