#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n), sum(n+1, 0);
    rep(i,n){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    ll ans = 1LL << 60;
    for(int i = 3; i < n; ++i){
        int l = 2, r = i;
        ll l1, l2, r1, r2;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(sum[mid-1] >= sum[i-1] - sum[mid-1]) r = mid;
            else l = mid;
        }
        ll s1 = llabs(sum[l-1] * 2 - sum[i-1]);
        ll s2 = llabs(sum[l] * 2 - sum[i-1]);
        if(s1 < s2){
            l1 = sum[l-1];
            r1 = sum[i-1] - sum[l-1];
        }
        else{
            l1 = sum[l];
            r1 = sum[i-1] - sum[l];
        }
        l = i+1; r = n+1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(sum[mid-1] - sum[i-1] >= sum[n] - sum[mid-1]) r = mid;
            else l = mid;
        }
        s1 = llabs(sum[l-1] * 2 -  sum[i-1] - sum[n]);
        s2 = llabs(sum[l] * 2 - sum[i-1] - sum[n]);
        if(s1 < s2){
            l2 = sum[l-1] - sum[i-1];
            r2 = sum[n] - sum[l-1];
        }
        else{
            l2 = sum[l] - sum[i-1];
            r2 = sum[n] - sum[l];
        }
        ll mi = min({l1, l2, r1, r2});
        ll mx = max({l1, l2, r1, r2});
        chmin(ans, mx - mi);
    }
    cout << ans << endl;
    return 0;
}
