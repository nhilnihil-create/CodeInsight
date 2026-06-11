#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    vector<int>a(n),b(n),c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        auto itr1 = lower_bound(a.begin(),a.end(),b[i]);
        auto itr2 = upper_bound(c.begin(),c.end(),b[i]);
        itr1--;
        ll l1 = distance(a.begin(),itr1);
        ll l2 = distance(itr2,c.end());
        ans += (l1+1)*l2;
    }
    cout << ans << endl;
}