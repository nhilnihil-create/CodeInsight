#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    rep(i, n) {
        cin >> b.at(i);
    }
    rep(i, n) {
        cin >> c.at(i);
    }
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    rep(i, n) {
        auto itr = lower_bound(a.begin(), a.end(), b.at(i));
        auto itc = upper_bound(c.begin(), c.end(), b.at(i));
        ans += (itr - a.begin()) * (c.end() - itc);
    }
    cout << ans << endl;
}