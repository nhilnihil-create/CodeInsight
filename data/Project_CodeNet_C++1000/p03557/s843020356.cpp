#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    vector<ll>a(n),b(n),c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans = 0;
    rep(i,n) {
        ll j = upper_bound(c.begin(),c.end(),b[i]) - c.begin();
        ll sum_c = c.size() - j;
        ll k = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
        ll sum_a = k;
        ans += sum_c*sum_a;
    }
    cout << ans << endl;
}
