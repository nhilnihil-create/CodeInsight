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
    ll n, c; cin >> n >> c;
    vi sum(200010, 0);
    map<ll, vector<pair<ll, ll>>> prog;
    rep(i, n){
        ll s, t, c;
        cin >> s >> t >> c;
        prog[c].emplace_back(make_pair(s, t));
    }
    for(auto &p: prog){
        sort(all(p.second));
        ll size = p.second.size();
        for(ll i=0; i<size; i++){
            ll s = p.second[i].first;
            ll t = p.second[i].second;
            if(i == 0){
                sum[s*2-1]++;
                sum[t*2+1]--;
            }
            else{
                // 前の番組から連続して録画したほうが良い場合
                if(s == p.second[i-1].second){
                    sum[s*2+1]++;
                    sum[t*2+1]--;
                }
                // 連続撮影しない場合
                else{
                    sum[s*2-1]++;
                    sum[t*2+1]--;
                }
            }
        }
    }

    ll ans = 0;
    repf(i, 200000){
        sum[i+1] += sum[i];
        chmax(ans, sum[i]);
    }
    cout << ans << endl;
}