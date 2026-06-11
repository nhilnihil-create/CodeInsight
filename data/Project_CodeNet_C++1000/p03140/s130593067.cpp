#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)

int main() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    rep(i,n){
        char p = a[i];
        char q = b[i];
        char r = c[i];
        if(p == q && q == r) continue;
        else if(p == q || q == r || r == p){
            ans++;
        }
        else ans += 2;
    }
    cout << ans << endl;
}
