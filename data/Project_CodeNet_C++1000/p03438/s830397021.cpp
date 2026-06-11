#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    ll asum = 0, bsum = 0;
    rep(i, N) {
        cin >> a[i];
        asum += a[i];
    }
    rep(i, N) {
        cin >> b[i];
        bsum += b[i];
    }
    ll ac = 0, bc = 0;
    rep(i, N) {
        if (a[i] < b[i]) {
            if ((b[i] - a[i]) % 2) {
                ac += (b[i] - a[i] + 1) / 2;
                bc++;
            } else {
                ac += (b[i] - a[i]) / 2;
            }
        }
        if (a[i] > b[i]) bc++;
    }
    //cout << ac << " " << bc << " " << asum << " " << bsum << endl;
    if (bsum - asum < max(ac, bc)) cout << "No\n";
    else cout << "Yes\n";
}