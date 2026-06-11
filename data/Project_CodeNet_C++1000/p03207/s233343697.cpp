#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    rep (i, n) cin >> p[i];
    auto it = max_element(ALL(p));
    int ans = 0;
    rep (i, n) ans+=p[i];
    ans -= *it / 2;
    cout << ans << endl;

    return 0;
}