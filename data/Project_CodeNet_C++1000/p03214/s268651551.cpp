#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = 0;
    int sum = accumulate(a.begin(), a.end(), 0);
    rep(i,n){
        if(abs(a[i] * n - sum) < abs(a[ans]*n - sum)){
            ans = i;
        }
    }
    cout << ans << endl;
}