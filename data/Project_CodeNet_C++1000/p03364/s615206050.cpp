#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;
string a[305];
ll cnt;

int main()
{
    cin>>n;
    for(ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            rotate(a[j].begin(), a[j].begin() + 1, a[j].end());
        }
        bool v = false;
        for(ll j = 0; j < n; j++)
        {
            for(ll k = 0; k < n; k++)
            {
                if(a[j][k] != a[k][j]) v = true;
            }
        }
        cnt += (!v);
    }
    printf("%lld\n", cnt * n);
    return 0;
}
