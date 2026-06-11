#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod = 1e9+9;
const int INF = 1e9;

int main(){
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n), b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    ll A_MAX = a[n-1];
    sort(b.rbegin(), b.rend());
    int ans = 1e9;
    rep(k,n+1){
        if (k > 0) h -= b[k-1];
        int cnt = 0;
        if (h > 0) cnt = (h+A_MAX-1) / A_MAX;
        ans = min(ans, k+cnt);
    }
    cout << ans << endl;
    return 0;
}
