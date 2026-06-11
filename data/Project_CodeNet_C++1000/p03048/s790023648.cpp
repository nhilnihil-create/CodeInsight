#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    rep(i,3001) {
        rep(j,3001) {
            int k = i*r+j*g;
            if(k<=n && (n-k)%b==0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}