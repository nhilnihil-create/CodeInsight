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
    int Q;
    cin >> Q;
    int MAX = 100000;
    vector<bool> p(MAX+1, true);
    p[0] = p[1] = false;
    rep2(i, 2, MAX){
        if(!p[i]) continue;
        for(int j = 2; i*j <= MAX; j++) p[i*j] = false;
    }
    int cnt[MAX+1];
    cnt[0] = 0;
    rep2(i, 1, MAX){
        cnt[i] = cnt[i-1];
        if(i%2 == 1 && p[i] && p[(i+1)/2]) cnt[i]++;
    }
    rep(i, Q){
        int l, r; cin >> l >> r; l--;
        cout << cnt[r]-cnt[l] << endl;
    }
}