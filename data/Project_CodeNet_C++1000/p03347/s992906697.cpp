#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;

int main(){
    int n ;cin >> n;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
        if(a[i] > i){
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i,n-1){
        if(a[i+1] > a[i]+1) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    rep(i,n-1){
        if(a[i] != a[i+1]-1) ans += a[i];
    }
    ans += a[n-1];
    cout << ans << endl;
}