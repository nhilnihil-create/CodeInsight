#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long x, long long y)
{
    if(x < y)
        return gcd(y, x);
    if(x % y == 0)
        return y;
    return gcd(y, x % y);
}

int main()
{
    int T;
    long long a, b, c, d;
    cin >> T;
    while(T --)
    {
        cin >> a >> b >> c >> d;
        if(a < b || d < b)
        {
            puts("No");
            continue ;
        }
        if(d >= b && c >= b)
        {
            puts("Yes");
            continue ;
        }
        if(d == b)
        {
            if(a % b <= c)
                puts("Yes");
            else
                puts("No");
            continue ;
        }
        long long k = gcd(b, d);
        a %= b;
        //cout << a << " " << k << endl;
        b -= a; 
        c -= a;
        long long ll = (b - 1), rr = c;
        if((ll > 0 && rr < 0) || (ll < 0 && rr > 0))
            puts("No");
        else if(ll / k <= rr / k)
            puts("Yes");
        else
            puts("No");
    }
}

