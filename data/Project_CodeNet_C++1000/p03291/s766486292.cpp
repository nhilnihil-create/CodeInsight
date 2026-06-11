#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

string s;
ll n;
ll a[100005][5];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>s;
    n = s.size();
    s = ' ' + s;
    a[0][3] = 1;
    for(ll i = 1; i <= n; i++)
    {
        if(s[i] == 'A' || s[i] == '?')
        {
            a[i][0] += a[i - 1][0] + a[i - 1][3];
            a[i][1] += a[i - 1][1];
            a[i][2] += a[i - 1][2];
            a[i][3] += a[i - 1][3];
        }
        if(s[i] == 'B' || s[i] == '?')
        {
            a[i][0] += a[i - 1][0];
            a[i][1] += a[i - 1][1] + a[i - 1][0];
            a[i][2] += a[i - 1][2];
            a[i][3] += a[i - 1][3];
        }
        if(s[i] == 'C' || s[i] == '?')
        {
            a[i][0] += a[i - 1][0];
            a[i][1] += a[i - 1][1];
            a[i][2] += a[i - 1][2] + a[i - 1][1];
            a[i][3] += a[i - 1][3];
        }
        a[i][0] %= M;
        a[i][1] %= M;
        a[i][2] %= M;
        a[i][3] %= M;
    }
    printf("%lld", a[n][2]);
    return 0;
}
