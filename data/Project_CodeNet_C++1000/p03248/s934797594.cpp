#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

string s;
ll a[100005];

int main()
{
    cin>>s;
    for(ll i = 0; i < s.size(); i++)
    {
        a[i + 1] = s[i] - '0';
    }
    if(a[1] == 0 || a[s.size()] == 1)
    {
        printf("-1\n");
        return 0;
    }
    for(ll i = 1; i <= s.size(); i++)
    {
        if(a[i] != a[s.size() - i])
        {
            printf("-1\n");
            return 0;
        }
    }
    a[s.size()] = 1;
    ll now = 1;
    for(ll i = 2; i <= s.size(); i++)
    {
        if(a[i])
        {
            for(ll j = now; j < i; j++)
            {
                printf("%lld %lld\n", j, i);
            }
            now = i;
        }
    }
    return 0;
}
