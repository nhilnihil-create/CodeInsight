#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n;
ll a[200005];
ll b[200005];
ll mn = 4e18;

int main()
{
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        b[i] = b[i - 1] + a[i];
    }
    ll j = 1, k = 3;
    for(ll i = 2; i <= n - 2;)
    {
        if(b[j + 1] * 2 <= b[i]) j++;
        else if(k < n && (b[k + 1] - b[i]) * 2 <= (b[n] - b[i])) k++;
        else
        {
            ll t1 = min(max(b[j], b[i] - b[j]), max(b[j + 1], b[i] - b[j + 1]));
            ll t2 = min(max(b[k] - b[i], b[n] - b[k]), max(b[k + 1] - b[i], b[n] - b[k + 1]));
            ll t3 = b[i] - t1;
            ll t4 = b[n] - b[i] - t2;
            mn = min(mn, max(t1, t2) - min(t3, t4));
            i++;
        }
    }
    cout<<mn<<endl;
    return 0;
}
