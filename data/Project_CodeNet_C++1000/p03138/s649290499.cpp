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

int main(){
    int n; ll k; cin >> n >> k;
    vector<int> bit(60,0);
    ll ans = 0;
    
    rep(i,n){
        ll a; cin >> a;
        rep(j,60) if ((a>>j) & 1ll) bit[j]++;
        ans += a ^ k;
    }

    vector<bool> kk(60,false);
    rep(i,60) if ((k>>i) & 1ll) kk[i] = true;

    for (int i = 59; i >= 0; i--) {
        if (!kk[i]) continue;
        ll ch = 0;
        rep(j,60) {
            if(j > i) {
                if (kk[j]) ch += ((ll)(n-bit[j])<<j);
                else ch += ((ll)bit[j]<<j);
            }
            else if(j == i) ch += ((ll)bit[j]<<j);
            else ch += ((ll)max(n-bit[j],bit[j])<<j);
        }
        chmax(ans, ch);
    }

    cout << ans << endl;
    return 0;
}