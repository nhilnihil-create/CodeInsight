#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
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
    ll k;
    cin >> k;
    vi a(k);
    rep(i, k) cin >> a[i];

    // nとしてあり得る範囲を[l, r)として逆順に処理していく
    ll l = 2, r = 3;
    for(ll i=k-1; i>=0; i--){
        ll nmin = ceil(1.0*l/a[i]);
        ll nmax = (r-1)/a[i];

        // 下限の係数が0ならmaxだけ頼る
        if(nmin <= 0){
            // どちらも0なら達成不可
            if(nmax <= 0){
                cout << -1 << endl;
                return 0;
            }
            // 範囲の更新
            else{
                l = a[i] * nmax;
                r = a[i] * (nmax+1);
            }
        }
        // 下限が得られている場合
        else{
            if(nmax <= 0 || nmax < nmin){
                cout << -1 << endl;
                return 0;
            }
            else if(nmin == nmax){
                l = a[i] * nmax;
                r = a[i] * (nmax+1);
            }
            else{
                l = a[i] * nmin;
                r = a[i] * (nmax+1);
            }
        }
    }
    cout << l << " " << r-1 << endl;
}