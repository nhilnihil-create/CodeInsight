#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n;
    cin >> n;
    vector<ll> s(n-1), c(n-1), f(n-1);
    rep1(i, n-1) cin >> c[i] >> s[i] >> f[i];
    ll sta;
    rep1(i, n-1){
        sta = i;
        ll t = 0;
        while (sta<n-1) {
            if (t>=s[sta]){
                if (t%f[sta]!=0) t += f[sta] - t%f[sta] + c[sta];
                else t += c[sta];
            }
            else t = s[sta]+c[sta];
            sta++;
        }
        cout << t << endl;
    }
    cout << 0 << endl;
    //printf("%.12f", ans);
}