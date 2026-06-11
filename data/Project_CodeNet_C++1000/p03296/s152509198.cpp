#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int ans = 0;
    rep(i, N - 1) {
        if (a[i] == a[i + 1]) {
            ans++;
            a[i + 1] = 101 + i;
        }
    }
    cout << ans << "\n";
}