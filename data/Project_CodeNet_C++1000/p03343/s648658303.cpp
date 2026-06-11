#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

const ll INF = 1ll<<60;

int main(){
    ll n, k, q; cin >> n >> k >> q;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    vector<ll> b = a; sort(all(b));
    ll ans = INF;
    rep(i,n){
        ll count = 1-k;
        vector<ll> c;
        rep(j,n){
            if(b[i] <= a[j]) count++;
            else{
                if(count >= 1){
                    vector<ll> d;
                    rep(s,count+k-1) d.pb(a[j-s-1]);
                    sort(all(d));
                    rep(s,count) c.pb(d[s]);
                }
                count = 1-k;
            }
        }
        if(count >= 1){
            vector<ll> d;
            rep(s,count+k-1) d.pb(a[n-s-1]);
            sort(all(d));
            rep(s,count) c.pb(d[s]);
        }
        if(c.size() < q) break;
        sort(all(c));
        chmin(ans,c[q-1]-c[0]);
    }
    cout << ans << endl;
}