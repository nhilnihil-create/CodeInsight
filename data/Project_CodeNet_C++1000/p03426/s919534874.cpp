#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
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
    ll h, w, d; cin >> h >> w >> d;
    vvi a(h+1, vi(w+1, 0));
    vector<pair<ll, ll>> idx(h*w+1);

    // 1-based-indexで入力処理
    repf(i, h){
        repf(j, w){
            cin >> a[i][j];
            idx[a[i][j]] = make_pair(i, j);
        }
    }

    // d個の巡回グループを作成
    vvi cycle(d+1, vi(0));
    for(ll i=1; i<=d; i++){
        // 最小値から順に消費魔力の累積和を計算
        ll sum = 0;
        cycle[i].push_back(sum);
        ll preIdx = i;
        ll nextIdx = i+d;
        // 制約より、h*wを超えることはない
        while(nextIdx<=h*w){
            // 消費魔力の計算
            sum += abs(idx[nextIdx].first-idx[preIdx].first)+abs(idx[nextIdx].second-idx[preIdx].second);
            // 累積和を追加
            cycle[i].push_back(sum);
            // 添字の更新
            preIdx = nextIdx;
            nextIdx += d;
        }
    }
    
    // q個の実技試験
    ll q; cin >> q;
    rep(i, q){
        ll l, r; cin >> l >> r;
        ll index = (l%d);
        if(index == 0) index += d;
        ll cycSrt = ((l-index)/d);
        ll cycEnd = ((r-index)/d);
        cout << cycle[index][cycEnd] - cycle[index][cycSrt] << endl;
    }
}