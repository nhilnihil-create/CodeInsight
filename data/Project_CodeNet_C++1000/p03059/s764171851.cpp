#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    double a, b, t;
    cin >> a >> b >> t;
    int ans = (t+0.5)/a;
    ans *= b;
    cout << ans << endl;
    return 0;
}