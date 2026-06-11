#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    for (int x : a) {
        while (x > 0) {
            if (x%2 == 0) {
                ans++;
                x/=2;
            }
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}