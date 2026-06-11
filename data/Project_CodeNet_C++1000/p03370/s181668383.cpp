#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);

    int n, x, m = 1000, b, s;
    cin >> n >> x;
    s= n;

    while (n--)
    {
        cin >> b;
        if (b < m) m = b;
        x -= b;
    }

    s = s + x/m;

    cout << s << endl;

    return 0;
}
