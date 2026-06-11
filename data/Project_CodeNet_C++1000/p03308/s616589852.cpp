#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
int main()
{
    int n;cin >> n;
    ll a[n+1];
    rep(i,n)cin >> a[i];
    sort(a,a+n);
    ll ans = a[n-1] - a[0];
    cout << ans << endl;
    return 0;
}