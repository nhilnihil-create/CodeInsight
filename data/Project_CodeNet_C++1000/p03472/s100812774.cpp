#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, h;

int main(void){
    cin >> n >> h;
    vector<lli> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    lli ma = *max_element(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    lli ans = 0;
    rep(i, n){
        if(b[i] <= ma) break;
        h-=b[i];
        ans++;
        if(h <= 0) break;
    }
    if(h > 0) ans+=(h+ma-1)/ma;
    cout << ans << endl;
    return 0;
}
