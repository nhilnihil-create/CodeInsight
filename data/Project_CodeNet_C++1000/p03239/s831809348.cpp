#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, u;
    cin >> n >> u;
    vector<int> c(n);
    vector<int> t(n);
    rep(i,n){
        int ci, ti;
        cin >> ci >> ti;
        c[i] = ci; 
        t[i] = ti;
    }

    int ans = 10000;
    rep(i,n){
        if(t[i] <= u) ans = min(ans,c[i]);
    }

    if(ans == 10000) cout << "TLE" << endl;
    else cout << ans << endl;
}
