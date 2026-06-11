#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    cin >> N;
    vector<ll> L, R;
    rep(i, N){
        ll l, r;
        cin >> l >> r;
        L.pb(l), R.pb(r);
    }
    sort(all(L), greater<ll>());
    sort(all(R));
    int i = 0;
    ll sum = 0;
    while(i < N && L[i] > R[i]) sum += L[i]-R[i], i++;
    ll ans = sum;
    if(i > 0){
        chmax(ans, sum-L[i-1]);
        chmax(ans, sum+R[i-1]);
    }
    if(2*i < N){
        chmax(ans, sum+L[i]);
        chmax(ans, sum-R[i]);
    }
    cout << 2*ans << endl;
}