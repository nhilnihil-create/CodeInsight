#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    
    vector<int> a(n, 0);
    rep(i, n-1) {
        if (s[i] == 'A' && s[i+1] == 'C') {
            a[i] = 1;
        } 
    }


    vector<int> v(n+1);
    rep(i, n) v[i+1] = v[i] + a[i];
    
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << v[r] - v[l] << endl;
    }
    return 0;
}