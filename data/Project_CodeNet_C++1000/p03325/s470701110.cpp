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
    vector<int> a(n);
    rep (i, n) cin >> a[i];
    ll ans=0;
    rep (i, n) {
        while(a[i] > 1) {
            if (a[i] % 2 == 0) {
                a[i] /= 2;
                ans++;
            }
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}