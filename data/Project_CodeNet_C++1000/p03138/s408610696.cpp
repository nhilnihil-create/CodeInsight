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
    ll n, k; cin >> n >> k;
    vi a(n), acnt(60, 0);
    rep(i, n){
        cin >> a[i];
        rep(bit, 60) if(a[i]&(1LL<<bit)) acnt[bit]++;
    }

    ll ans = 0;
    for(ll i=60; i>=-1; i--){
        // X=K以外の場合で、iビット目が0だったら飛ばす。
        if(i != -1 && !(k&(1LL<<i))) continue;

        // iビット目より下位のビットは自由なので、上位ビットから貪欲法で求める。
        ll tmp = 0;
        for(ll bit = 60; bit>=0; bit--){
            ll mask = (1LL<<bit);

            // Kと一致していなきゃいけない箇所ならば
            if(bit>i){
                if(k&mask) tmp += mask*(n-acnt[bit]);
                else tmp += mask*acnt[bit];
            }
            // Kと最初に異なる場所
            else if(bit == i){
                tmp += mask*acnt[bit];
            }
            // 自由な場所
            else{
                tmp += mask*max(acnt[bit], n-acnt[bit]);
            }
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
}