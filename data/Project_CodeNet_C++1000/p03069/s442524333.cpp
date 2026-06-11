#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> w(n), b(n);
    int W = 0, B = 0;
    rep(i,n){
        if(s[i]=='.') W++;
        w[i] = W;
    }
    for(int i = n-1; i >= 0; --i) {
        if(s[i]=='#') B++;
        b[i] = B;
    }
    int ans = 1e9;
    ans = min(n-W, n-B);
    for(int i = 0; i < n; ++i) {
        int r = max(0, i+1-w[i]);
        int l = max(0, n-i-1-b[i]);
        ans = min(ans, r+l);

    }
    cout << ans << endl;
    return 0;
}