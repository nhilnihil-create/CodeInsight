#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, X, tmp;
    cin >> N >> X;
    vector<int> x(N);
    rep(i,N) {
        cin >> tmp;
        x.at(i) = abs(tmp - X);
    }
    int ans = x.at(0);
    rep(i,N) ans = gcd(ans, x.at(i));
    cout << ans << endl;
}
