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

void count(map<ll, ll> &cnt, ll num){
    for(ll i=0; i<=40; i++) if(num & (1LL << i)) cnt[i]++;
}

int main(){
    Init();
    ll n, k;
    cin >> n >> k;
    vi a(n), cand;
    rep(i, n) cin >> a[i];

    // 全ての部分列の美しさを求める
    for(ll i=0; i<n; i++){
        ll pre = 0;
        for(ll j=i; j<n; j++){
            pre += a[j];
            cand.emplace_back(pre);
        }
    }

    // 解を求める
    ll ans = 0;
    for(ll i=40; i>=0; i--){
        ll cnt = 0;
        ans += (1LL << i);
        for(ll c=0; c<cand.size(); c++) if((ans&cand[c]) == ans) cnt++;
        if(cnt < k) ans -= (1LL << i);
    }
    cout << ans << endl;
}