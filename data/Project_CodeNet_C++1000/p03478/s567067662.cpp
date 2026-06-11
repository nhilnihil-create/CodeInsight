#include <bits/stdc++.h>
using namespace std;

int sumOfDigits( int x )
{
    int sum = 0;
    while ( x  > 0 )
    {
        sum += x % 10;
        x /= 10;
    }
    
    return sum;
}

int main(void)
{
    int n,a,b;
    cin >> n >> a >> b;
    
    int ans = 0;
    for ( int i = 1; i <= n; i++ )
        if ( sumOfDigits(i) >= a && sumOfDigits(i) <= b )
            ans += i;
    
    cout << ans << endl;
}
