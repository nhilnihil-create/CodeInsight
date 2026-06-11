#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    if(a[0] != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    a.push_back(0);
    ll ans = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(a[i] == a[i+1] - 1) continue;
        else if(a[i] < a[i+1] - 1)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            ans += a[i];
        }
    }
    cout << ans << endl;

    return 0;
}