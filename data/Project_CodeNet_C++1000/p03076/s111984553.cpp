#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    vector<int> a(5);
    rep(i, 0, 5) cin >> a[i];
    int mn = 10;
    rep(i, 0, 5){
        if(a[i]%10 == 0) continue;
        mn = min(mn, a[i]%10);
    }
    int ans = 0;
    rep(i, 0, 5){
        if(a[i]%10 == 0) ans += a[i];
        else ans += 10*(a[i]/10 + 1);
    }
    cout << ans - 10 + mn << endl;
    return 0;
}
