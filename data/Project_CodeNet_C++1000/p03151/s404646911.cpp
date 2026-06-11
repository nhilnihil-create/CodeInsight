#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
#define all(v) v.begin(), v.end()
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;cin >> n;
    vector<ll> a(n,0);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> b(n,0);
    ll b_sum = 0;
    rep(i,n){
        cin >> b[i];
        b_sum += b[i];
    }
    if(sum < b_sum){
        cout << -1 << "\n";
        return 0;
    }
    sum = 0;
    vector<ll> amari;
    rep(i,n){
        if(a[i] < b[i]){
            sum -= (b[i] - a[i]);
            a[i] = b[i];
        }else{
            sum += (a[i] - b[i]);
            amari.emplace_back(a[i] - b[i]);
            a[i] = b[i];
        }
    }
    sort(all(amari));
    ll res = 0;
    rep(i,amari.size()){
        if(sum >= amari[i]){
            ++res;
            sum -= amari[i];
        }else break;
    }
    cout << n - res << "\n";
    return 0;
}