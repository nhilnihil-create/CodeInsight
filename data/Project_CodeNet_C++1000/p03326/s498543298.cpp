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
    ll n, m, ans = 0; cin >> n >> m;
    vi x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    for(ll i=0; i<(1LL<<3); i++){
        vi sign(3, 1);
        vector<tuple<ll, ll, ll, ll>> score(n);
        for(ll m=0; m<3; m++) if(i&(1LL<<m)) sign[m] = -1;
        rep(i, n) score[i] = make_tuple(sign[0]*x[i] + sign[1]*y[i] + sign[2]*z[i], x[i], y[i], z[i]);
        sort(all(score), greater<tuple<ll, ll, ll, ll>>());
        ll xsum = 0, ysum = 0, zsum = 0;
        rep(i, m){
            xsum += get<1>(score[i]);
            ysum += get<2>(score[i]);
            zsum += get<3>(score[i]);
        }
        chmax(ans, abs(xsum)+abs(ysum)+abs(zsum));
    }
    cout << ans << endl;
}