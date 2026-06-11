/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int cntc = 0;
    int first = 0;
    bool all9 = true;
    while(n > 0)
    {
        cntc++;
        if(n > 9)
            all9 &= (n % 10 == 9);
        first = n % 10;
        n /= 10;
    }
    if(all9)
        cout << first + (cntc - 1) * 9 << "\n";
    else
        cout << first - 1 + (cntc - 1) * 9 << "\n";
    return 0;
}
