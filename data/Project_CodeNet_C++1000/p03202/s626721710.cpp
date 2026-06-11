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
    int A[N];
    rep(i, N) cin >> A[i];
    //(l,r]
    ll l = 0, r = INF;
    while(r-l > 1){
        ll n = (l+r)/2;
        bool able = true;
        map<int, ll> mp;
        rep(i, N){
            if(i == 0 || A[i] > A[i-1]) continue;
            if(n == 1) {able = false; break;}
            mp[A[i]]++;
            map<int, ll>::iterator it = mp.find(A[i]);
            it++;
            while(it != mp.end()) it = mp.erase(it);
            int now = A[i];
            while(now > 0 && mp[now] == n){
                mp.erase(now--);
                mp[now]++;
            }
            if(now == 0) {able = false; break;}
        }
        if(able) r = n;
        else l = n;
    }
    cout << r << endl;
}