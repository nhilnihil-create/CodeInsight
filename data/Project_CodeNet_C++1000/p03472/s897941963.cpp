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
    ll n, h; cin >> n >> h;
    vector<pair<pair<ll, ll>, ll>> a(n);
    vector<pair<ll, ll>> b(n);

    // 添字を含んで入力処理
    rep(i, n){
        ll ai, bi; cin >> ai >> bi;
        a.push_back(make_pair(make_pair(ai, bi), i));
        b.push_back(make_pair(bi, i));
    }
    // 降順に整列
    sort(all(a), greater<pair<pair<ll, ll>, ll>>());
    sort(all(b), greater<pair<ll, ll>>());

    // 通常攻撃の最大値
    ll NormalAttack = a[0].first.first;
    ll DontThrowA = a[0].second;

    // 答え算出用
    ll cnt = 0;

    // 通常攻撃の最大値より強いものは投げれるだけ投げる
    ll ThrowAttack = a[0].first.second;
    ll cur = 0;
    if(b[cur].second == DontThrowA) cur++;
    while(h>0 && h>ThrowAttack && cur<n && b[cur].first>NormalAttack){
        // 攻撃を行いHPを減少、攻撃回数を増加
        h -= b[cur].first;
        cnt++;
        // カーソルをずらす（通常攻撃に使うやつだったら更にずらす）
        cur++;
        if(cur<n && b[cur].second == DontThrowA) cur++;
    }

    // 敵のHPが残っているなら
    if(h >= 1){
        // 通常攻撃のほうが強い場合
        if(ThrowAttack == -1 || ThrowAttack <= NormalAttack){
            cnt += ceil(1.0*h/NormalAttack);
        }
        // 投げたほうが強い場合
        else{
            cnt++; h-=ThrowAttack;
            if(h>=1) cnt += ceil(1.0*h/NormalAttack);
        }
    }

    // 結果の出力
    cout << cnt << endl;
}