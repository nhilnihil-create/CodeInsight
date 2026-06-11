#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        if(a == b)
        {
            cout << 2*(a-1) << endl;
            continue;
        }
        ll sum = a * b;
        sum--;
        ll sq = sqrt(sum);
        ll ans = 2 * sq - 1;
        if(sum / sq == sq)
        {
            cout << ans-1 << endl;
            continue;
        }
        if(sq * (sq+1) >= a*b)
        {
            cout << ans-2 << endl;
            continue;
        }
        cout << ans << endl;
    }
}
