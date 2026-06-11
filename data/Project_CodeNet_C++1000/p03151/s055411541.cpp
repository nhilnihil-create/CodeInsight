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
    ll n; cin >> n;
    vi a(n), b(n), diff(n);
    ll sum_a = 0, sum_b = 0;

    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n){
        sum_a += a[i], sum_b += b[i];
        diff[i] = a[i]-b[i];
        if(diff[i] < 0) diff[i] = (1LL<<50);
    }
    sort(all(diff));

    // 総和は変えられないので、元々の準備度が必要な準備度の合計を超えていない場合は達成不可能
    if(sum_a < sum_b){
        cout << -1 << endl;
        return 0;
    }

    // 許される超過量
    ll excess = sum_a - sum_b;
    ll cnt = 0, pos = 0;
    for(; pos<n; pos++){
        if(cnt + diff[pos] > excess) break;
        else cnt += diff[pos];
    }
    cout << n-pos << endl;
}