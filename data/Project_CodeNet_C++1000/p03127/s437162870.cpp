#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define ll long long

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return(b);
    }
    else
    {
        return(gcd(b, a % b));
    }
}

int main()
{
    int n,ans;

    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    //最大公約数
    ans = a[0];
    for (int i=1;i<n;++i) {
        ans = gcd(ans, a[i]);
    }

    cout << ans << endl;
    return(0);
}
