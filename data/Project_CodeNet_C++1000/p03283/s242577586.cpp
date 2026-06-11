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
    ll n, m, q; cin >> n >> m >> q;
    vvi lr(n+2, vi(n+2, 0));
    rep(i, m){
        ll l, r; cin >> l >> r;
        lr[l][r]++;
    }
    repf(i, n) repf(j, n) lr[i][j+1] += lr[i][j];
    repf(i, n) repf(j, n) lr[j+1][i] += lr[j][i];

    rep(i, q){
        ll l, r; cin >> l >> r;
        cout << lr[r][r] - lr[l-1][r] << endl;
    }
}