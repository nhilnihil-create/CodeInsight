#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    int n;
    cin >> n;
    ll t=0;
    vector<int> a(n+2),diff(n+2);
    a[0] =0;a[n+1] = 0;
    rrep(i,n){
        cin >> a[i];
    }
    rrep(i,n+1){
        diff[i] = abs(a[i] - a[i-1]);
        t+=diff[i];
    }

    rrep(i,n){
        ll ans = t - diff[i] - diff[i+1];
        ans += abs(a[i+1]-a[i-1]);
        cout << ans <<endl;
    }
    return 0;
}