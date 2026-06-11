#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    int n = a[N - 1], k = n / 2;
    cout << n << " ";
    auto i = lower_bound(a.begin(), a.end(), k);
    if (*i * 2 - n < n - *(i - 1) * 2) cout << *i << endl;
    else cout << *(i - 1) << endl;
    return;
}

int main() {
    solve();
}
