#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

/* RMQ2：[0,n-1] について、区間ごとの最大値を管理する構造体
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最大の要素を取得。O(log(n))
*/
template <typename T>
struct RMQ2 {
    ll n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RMQ2(ll n_) : n(), dat(n_ * 4, 0) { // 葉の数は 2^x の形
        ll x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
 
    void update(ll i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = max(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
 
    // the maximum element of [a,b)
    T query(ll a, ll b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a || b <= l) {
            return -INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
};

int main(){
    ll N;
    cin >> N;
    vector<ll> h(N,0);
    for(ll i=0;i<N;i++)cin>>h[i];
    vector<ll> A(N,0);
    for(ll i=0;i<N;i++)cin>>A[i];

    //dp[i]は最後の高さがiにおける美しさの和の最大値
    vector<ll> dp(N+1,0);

    RMQ2<ll> tree(N+1);

    //花を一つずつ解禁
    for(ll i=0;i<N;i++){
        chmax(dp[h[i]],tree.query(0,h[i])+A[i]);
        tree.update(h[i],dp[h[i]]);
    }

    ll ans=-INF;
    for(ll i=0;i<=N;i++)chmax(ans,dp[i]);

    print(ans)


    return 0;
}
