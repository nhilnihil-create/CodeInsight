#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n,0);
    for (int i = 1; i<n; i++) {
        a[i] = a[i-1];
        if (s[i] == 'C' && s[i - 1] == 'A') {
            a[i]++;
        }
    }
    rep(i, q) {
        int l,r;
        cin >> l >> r;
        cout << a[r - 1] - a[l-1] << endl;
    }
    return 0;
}
