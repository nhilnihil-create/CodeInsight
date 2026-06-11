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
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);    
    // 頻度計算用
    map<ll, ll> mpe;
    map<ll, ll> mpo;
    vector<pair<ll, ll>> ve;
    vector<pair<ll, ll>> vo;
    
    // 入力処理
    ll n, ans = 0; cin >> n;
    rep(i, n){
        ll in; cin >> in;
        // 偶奇判定
        (i%2 == 0) ? mpe[in]++ : mpo[in]++;
    }

    // (回数, 数字)のペアを回数をキーに降順でソート
    for(auto p: mpe) ve.push_back(make_pair(p.second, p.first));
    for(auto p: mpo) vo.push_back(make_pair(p.second, p.first));
    sort(all(ve), greater<pair<ll, ll>>());
    sort(all(vo), greater<pair<ll, ll>>());

    // 偶数列・奇数列でそれぞれ同じ数字しか存在しない場合
    if((n/2-ve[0].first == 0) && (n/2-vo[0].first == 0)){
        // 偶数列と奇数列の最頻値が異なる数字である場合
        if(ve[0].second != vo[0].second) ans = 0;
        // 同じ数字が使われる場合は書き換えが少ない数列側を変える
        else ans = min(n/2-ve[1].first, n/2-vo[1].first);
    }

    // 異なる数字が混在する場合
    else{
        // 偶数列と奇数列の最頻値が異なる数字である場合
        if(ve[0].second != vo[0].second) ans = n/2-ve[0].first + n/2-vo[0].first;
        // 同じ数字が使われる場合は書き換えが少ない数列側を変える
        else{
            // 偶数列を2番目に頻度の高い数字で書き換え、奇数列を最も頻度の高い数字で書き換える
            if(n/2-ve[1].first <= n/2-vo[1].first) ans = n/2-ve[1].first + n/2-vo[0].first;
            // 奇数列を2番目の頻度の高い数字で書き換え、偶数列を最も頻度の高い数字で書き換える
            else ans = n/2-vo[1].first + n/2-ve[0].first;
        }
    }

    // 出力
    cout << ans << endl;
}