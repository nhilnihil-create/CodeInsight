#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n , h[N] , f[N];

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n; ++i)
    {
        cin >> h[i];
    }
    f[1] = 0;
    f[0] = 99999;
    h[0] = 99999;
    for(int i = 2 ; i <= n; ++i)
    {
        f[i] = min(f[i-1] + abs(h[i-1] - h[i]), f[i-2] + abs(h[i-2] - h[i]));
    }
    cout << f[n] << endl;
    return 0;
}
