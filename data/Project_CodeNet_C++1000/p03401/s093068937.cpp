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
    ll n; cin >> n;
    
    // 0とn+1が終点（0）
    vi a(n+2, 0);
    vi b(n+2, 0);
    // 予定変更がない場合の移動費
    ll sum = 0;

    // a1~anを入力するとともに、各iとi-1の移動費を計算
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        b[i] = abs(a[i-1]-a[i]);
        sum += b[i];
    }
    b[n+1] = abs(a[n]-a[n+1]);
    sum += b[n+1];
    
    // i番目の場所に訪れない場合をそれぞれ出力
    for(ll i=1; i<=n; i++) cout << sum - b[i] - b[i+1] + abs(a[i-1]-a[i+1]) << endl;
    return 0;
}