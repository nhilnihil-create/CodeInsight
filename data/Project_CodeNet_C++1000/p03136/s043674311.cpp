#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int tot = 0;
    int L[n];
    rep(i,n) {
        cin >> L[i];
        tot += L[i];
    }

    rep(i,n) {
        if ( tot-L[i] <= L[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}