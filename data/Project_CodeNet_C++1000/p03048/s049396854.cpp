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
    ll r, g, b, n;
    cin >> r >> g >> b >> n;
    ll ans = 0;

    for(ll i=0; i<=3000; i++){
        // 既にnを超えていたらループを抜ける
        ll rb = r*i;
        if(rb > n) break;
        for(ll j=0; j<=3000; j++){
            // 既にnを超えていたらループを抜ける
            ll gb = g*j;
            if(rb+gb > n) break;

            // 青色の箱を整数個買って条件を達成できるか確認
            if((n-(rb+gb))%b == 0) ans++;
        }
    }
    cout << ans << endl;
}