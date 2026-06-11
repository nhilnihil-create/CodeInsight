#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll z, w;
    cin >> n >> z >> w;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = llabs(a[n-1] - w);
    if(n > 1) chmax(ans, llabs(a[n-2] - a[n-1]));
    cout << ans << endl;
    return 0;
}
