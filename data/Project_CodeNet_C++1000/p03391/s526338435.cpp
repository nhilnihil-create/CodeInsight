#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, A, B, minB = 2e9;
    cin >> N;
    ll s = 0, ans;
    rep(i, N) {
        cin >> A >> B;
        s += B;
        if (A > B) {
            minB = min(minB, B);
        }
    }
    if (minB == 2e9) ans = 0;
    else ans = s - minB;
    cout << ans << endl;
}