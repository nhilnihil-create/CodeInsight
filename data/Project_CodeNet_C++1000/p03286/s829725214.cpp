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

string binRep(ll n){
    string s = "";
    while(n != 0){
        ll m = n%2;
        (m == 0) ? s="0"+s : s="1"+s;
        n /= 2;
    }
    return s;
}

int main(){
    Init();
    ll n, m; cin >> n;

    // 0の場合は0を出力
    if(n == 0){ cout << 0 << endl; return 0; }

    // 出力用
    string ans = "";

    // 0以外の場合は-2で割って各桁の表記を決めていく
    while(n != 0){
        m = abs(n%(-2));
        ans += (char)('0'+m);
        n = (n-m)/(-2);
    }

    // 反転して出力
    reverse(all(ans));
    cout << ans << endl;
}