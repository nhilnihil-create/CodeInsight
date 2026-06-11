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
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> prf(n, vector<pair<ll, ll>>(0));

    rep(i, m){
        ll p, y;
        cin >> p >> y;
        p--;
        prf[p].push_back(make_pair(y, i));
    }
    vector<pair<ll, ll>> city(m);
    rep(i, n){
        if(prf[i].size() >= 2) sort(all(prf[i]));
        rep(j, prf[i].size()){
            city[prf[i][j].second] = make_pair(i+1, j+1);
        }
    }

    rep(i, m) cout << setfill('0') << setw(6) << city[i].first << setfill('0') << setw(6) << city[i].second << endl; 
}