#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a;}

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> x(n);
    rep(i,n) cin >> x.at(i);
    x.push_back(s);
    sort(x.begin(), x.end());
    vector<int> d(n);
    rep(i,n) d.at(i) = x.at(i+1) - x.at(i);
    if (d.size() == 1) {
        cout << d.at(0) << endl;
        return 0;
    }
    int ans = gcd(d.at(0), d.at(1));
    for (int i = 2; i < n; ++i) ans = gcd(ans, d.at(i));
    cout << ans << endl;
    return 0;
}

