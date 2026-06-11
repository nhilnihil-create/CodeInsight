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
    ll d, g; cin >> d >> g;
    vi p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];

    // ボーナス取得の組み合わせは最大2^10なので全て試す。
    // 不足分は完答していない問題の中で基本スコアが最大の問題を解いて補完する。
    ll ans = INFLL;
    for(ll bit = 0; bit<(1LL<<d); bit++){
        ll sumScore = 0;
        ll sumCnt = 0;
        vi chk(d, 0);
        for(ll m = 0; m<10; m++){
            if(bit&(1LL<<m)){
                chk[m]++;
                sumScore += (m+1)*100*p[m]+c[m];
                sumCnt += p[m];
            }
        }
        if(sumScore < g){
            for(ll m = d-1; m>=0; m--){
                if(chk[m] == 0){
                    ll addCnt = min((ll)(ceil(1.0*(g - sumScore)/((m+1)*100))), p[m]);
                    sumScore += addCnt*(m+1)*100;
                    sumCnt += addCnt;
                    break;
                }
            }
        }
        if(sumScore < g) continue;
        chmin(ans, sumCnt);
    }
    cout << ans << endl;
}