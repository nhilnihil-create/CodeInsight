#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    int pos_1=0;
    rep(i, n) {
        cin >> a[i];
        if (a[i] == 1) pos_1=i;
    }
    int ans = 0;
    ans = (n+k-3)/(k-1);

    cout << ans << endl;
}