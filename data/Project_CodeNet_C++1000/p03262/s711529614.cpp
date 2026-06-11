#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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

int main(void)
{
    int n, x,ans;

    cin >> n >> x;
    vector<int> xx(n);
    rep(i, n) {
        cin >> xx[i];
    }
    
    ans = abs(x - xx[0]);
    for (int i=1;i<n;++i) {
        ans = gcd(abs(x - xx[i]), ans);
    }

    cout << ans << endl;

    return 0;
}