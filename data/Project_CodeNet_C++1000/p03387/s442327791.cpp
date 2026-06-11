#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    vector<int> a(3);
    rep(i, 0, 3) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    ans += a[2] - a[1];
    a[0] += ans;
    if(a[0]%2 == a[2]%2) ans += (a[2] - a[0])/2;
    else ans += (a[2] - a[0] + 1)/2 + 1;
    cout << ans << endl;
    return 0;
}
