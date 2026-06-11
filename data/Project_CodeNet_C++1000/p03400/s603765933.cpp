#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int ans = 0;
    rep(i, 0, n){
        ans += (d + a[i] - 1)/a[i];
    }
    cout << ans + x << endl;
    return 0;
}
