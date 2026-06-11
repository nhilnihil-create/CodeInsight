#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    long int x;
    cin >> x;
    int m[n];
    for ( int i = 0; i < n; i++ )
        cin >> m[i];
    
    int min = m[0];
    for ( int i = 0; i < n; i++ )
    {
        x -= m[i];
        if ( min > m[i] )
            min = m[i];
    }
    
    int ans = n;
    ans += x / min;
    cout << ans << endl;
}
