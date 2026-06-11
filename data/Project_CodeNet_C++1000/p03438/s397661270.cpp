#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n;
ll a[10101], b[10101];

int main()
{
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ca = 0, cb = 0;
    rep(i, n)
    {
        if(a[i] >= b[i])
        {
            cb += a[i] - b[i];
        }
        else
        {
            if(a[i] % 2 != b[i] % 2)
            {
                b[i]++;
                cb++;
            }
            ca += (b[i] - a[i]) / 2;
        }
    }
    //cout << ca << " " << cb << endl;
    if(ca >= cb)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}