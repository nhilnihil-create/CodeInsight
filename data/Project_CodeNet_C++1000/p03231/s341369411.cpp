#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long int gcd(long long int a,long long int b)
{
    while(a % b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return b;
}
int main()
{
    long long int n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    long long int g = gcd(m,n);
    long long int l = n * m / g;
    n /= g;
    m /= g;
    bool flag = true;
    for(int i = 0;i < g;i++)
    {
        if(s[i * n] != t[i * m])
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout << l << "\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}