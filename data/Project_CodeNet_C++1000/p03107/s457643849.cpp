#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

string S;
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> S;
    int r = 0, b = 0;
    rep(i, S.size()) {
        if (S[i]=='0') {
            if (b>0) b--;
            else r++;
        }
        else {
            if (r>0) r--;
            else b++;
        }
    }
    cout << S.size()-r-b << endl;
}