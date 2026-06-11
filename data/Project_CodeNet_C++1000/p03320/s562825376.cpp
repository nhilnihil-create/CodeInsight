#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back

int bexp(int a, int b, int mod)
{
    int res = 1;
    if (mod <= 0)
        return 0;

    while (b)
    {
        if (b & 1) res = (res * a) % mod;

        a = (a * a) % mod; 
        b >>= 1;
    }
    return res;
}

#define N 500010
#define MOD 1000000007

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int sum(int n)
{
    int res = 0;
    while (n)
        res += n % 10, n /= 10;
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n;
    cin >> n;
    int i = 1;
        
    while (n && i < 10)
    {
        cout << i << "\n";
        i++;
        n--;
    }

    i = 19;
    int p = 10;
    while (n)
    {
        while (i < sum(i) * p && n)
        {
            n--;
            cout << i << "\n";
            i += p;
        }
        i -= p;
        p *= 10;
        i += p;
    }
    return 0;
}
    