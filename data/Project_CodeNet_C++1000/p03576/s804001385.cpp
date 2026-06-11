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
    ll n, k, ans = INFLL;
    cin >> n >> k;
    vi x(n), y(n);
    vector<pair<ll, ll>> xy(n), yx(n);
    rep(i, n){
        cin >> x[i] >> y[i];
        xy[i] = make_pair(x[i], y[i]);
        yx[i] = make_pair(y[i], x[i]);
    }
    sort(all(xy));
    sort(all(yx));

    for(ll sx=0; sx<n; sx++){
        for(ll sy=0; sy<n; sy++){
            for(ll gx=sx; gx<n; gx++){
                for(ll gy=sy; gy<n; gy++){
                    ll cnt = 0;
                    for(ll i=0; i<n; i++){
                        if(xy[sx].first <= x[i] && x[i] <= xy[gx].first && yx[sy].first <= y[i] && y[i] <= yx[gy].first) cnt++;
                    }
                    if(cnt >= k) chmin(ans, (xy[gx].first-xy[sx].first)*(yx[gy].first-yx[sy].first));
                }
            }
        }
    }
    cout << ans << endl;
}