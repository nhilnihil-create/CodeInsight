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
    
    // 入力処理
    ll n; cin >> n;
    vi c(n), s(n), f(n, 1);
    rep(i, n) cin >> c[i] >> s[i] >> f[i];

    // 始点をiとして全てをシミュレート
    for(ll i=0; i<n; i++){
        ll time = s[i]+c[i];
        for(ll j=i+1; j<n; j++){
            // 最初の出発時間を超えていない場合
            if(time < s[j]) time = s[j];
            // 出発時間は過ぎているが発車間隔にあっていない場合
            else if(time%f[j] != 0) time += f[j]-time%f[j];
            // 移動時間を加算
            time += c[j];
        }
        // 結果の出力
        cout << time << endl;
    }
}