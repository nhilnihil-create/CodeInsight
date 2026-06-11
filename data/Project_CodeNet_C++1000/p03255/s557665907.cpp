#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, X;
ll x[200005];
ll y[200005];
ull ans = 18446744073709551615;

int main()
{
    cin>>n>>X;
    for(ll i = 1; i <= n; i++)
    {
        cin>>x[i];
        y[i] = y[i - 1] + x[i];
    }
    for(ll i = 1; i <= n; i++)
    {
        ull now = 0;
        ll k = 2;
        now += k * k * (y[n] - y[max(n - i, 0LL)]);
        for(ll j = n - i; j >= 1; j -= i)
        {
            now += (2 * k + 1) * (y[j] - y[max(j - i, 0LL)]);
            k++;
        }
        now += i * X;
        now += y[n] - y[max(n - i, 0LL)];
        ans = min(ans, now);
    }
    cout<<ans + n * X<<endl;
    return 0;
}
