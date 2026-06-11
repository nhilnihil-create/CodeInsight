#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    n--;
    vector<int> c(n), s(n), f(n);
    rep(i,n) cin >> c[i] >> s[i] >> f[i];
    rep(i,n) {
        int ans = 0;
        for(int j = i; j < n; ++j) {
            ans = max(ans, s[j]);
            int d = ans-s[j];
            if(d%f[j]==0) d = 0;
            else d = f[j]-(d%f[j]);
            ans+=d+c[j];
        }
        cout << ans << endl;
    } 
    cout << 0 << endl;
    return 0;
}