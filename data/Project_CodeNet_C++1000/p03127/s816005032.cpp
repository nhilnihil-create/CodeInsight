#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(vector<int> a) {
    int ans = a[0];
    for (int i = 1; i < a.size(); i++) {
        ans = __gcd(a[i], ans);
    }
    return ans;
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = gcd(a);

    cout << ans << endl;
}