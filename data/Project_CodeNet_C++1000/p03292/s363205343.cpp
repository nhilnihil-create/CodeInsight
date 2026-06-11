#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
#define int long long
signed main()
{
    int a[3] ;
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    reverse(a,a+3);
    int ans = 0;
    ans += abs(a[1] - a[0]);
    ans += abs(a[2] - a[1]);
    cout << ans << endl;

    return 0;
}