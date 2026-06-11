#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, ans;
    double t, a;
    int mn = 1e9;
    cin >> n >> t >> a;
    rep(i,n) {
        int h, d;
        cin >> h;
        d = (t*1000-h*6)-a*1000;
        if(d<0) d*=-1;
        if(mn>d) {
            mn = d;
            ans = i+1;
        }
    }
    cout << ans << endl;
    return 0;
}