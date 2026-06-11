#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> t, v, vv;
    ll sum_t = 0;
    t.resize(n+1);
    v.resize(n+1);
    v[0] = 0;
    t[0] = 0;
    rep(i,n){
        cin >> t[i+1];
        sum_t += t[i+1]*2;
        t[i+1] = sum_t;
    }
    rep(i,n){
        cin >> v[i+1];
        v[i+1] *= 2;
    }
    double sum_l = 0.0;
    v.push_back(0);
    vv = vector<ll>(sum_t + 1, INF);
    vv[0] = 0;
    vv[sum_t] = 0;
    int flag = 1;
    for(ll i = 1; i < sum_t; i++){
        chmin(vv[i], vv[i-1] + 1);
        chmin(vv[i], v[flag]);
        if(i == t[flag]){
            chmin(vv[i], v[flag + 1]);
            flag++;
        }
    }
    for(ll i = sum_t; i > 0; i--){
        chmin(vv[i-1], vv[i] + 1);
    }
    for(ll i = 0; i < sum_t; i++){
        sum_l += (vv[i] + vv[i+1]) / 2.0;
    }
    cout << fixed << setprecision(12) << sum_l * 0.25 << endl;
    return 0;
}