#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, k;

int main(void){
    cin >> n >> k;
    vector<lli> x(n);
    rep(i, n) cin >> x[i];
    lli ans = 1e18;
    rep(i, n-k+1){
        lli u = min(abs(x[i]), abs(x[i+k-1]));
        lli v = abs(x[i]-x[i+k-1]);
        ans = min(ans, u+v);
    }
    cout << ans << endl;
    return 0;
}
