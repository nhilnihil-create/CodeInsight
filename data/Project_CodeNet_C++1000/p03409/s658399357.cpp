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
    ll n, ans = 0; cin >> n;
    set<pair<ll, ll>> red;
    set<pair<ll, ll>> blue;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        red.insert(make_pair(-a, -b));
    }
    rep(i, n){
        ll c, d;
        cin >> c >> d;
        blue.insert(make_pair(c, d));
    }

    for(auto &bp: blue){
        ll c = bp.first, d = bp.second;
        auto it = red.upper_bound({-c, 0});
        auto p = red.end();

        for(; it != red.end(); it++){
            ll a = (*it).first;
            ll b = (*it).second;
            if(p == red.end()){ if(b > (-d)) p = it; }
            else if((*p).second > b && b > (-d)) p = it;
        }
        if(p != red.end()){ ans++; red.erase(p); }
    }
    cout << ans << endl;
}