#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];

    ll sA = 0, sB = 0;

    repi(i, n, 0)
    {
        cin >> a[i];
        sA += a[i];
    }
    repi(i, n, 0)
    {
        cin >> b[i];
        sB += b[i];
    }

    ll m = sB - sA;
    if (m < 0)
    {
        //絶対終わらない
        cout << "No" << endl;
    }
    else
    {
        //絶対終わる
        ll c1 = 0, c2 = 0;
        repi(i, n, 0)
        {
            if (a[i] > b[i])
            {
                c1 += a[i] - b[i]; //絶対終わるやつ
            }
            else
            {
                c2 += (b[i] - a[i]) / 2; //終わるかどうか怪しいやつ
            }
        }
        // cout << c1 << " " << c2 << endl;
        if (c2 < c1)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}