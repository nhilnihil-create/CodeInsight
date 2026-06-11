#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n , k , h[N] , f[N];

int main()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n; ++i)
    {
        cin >> h[i];
        f[i] = INT_MAX;
    }
    f[1] = 0;
    for(int i = 2 ; i <= n; ++i)
    {
        for(int j = 1 ; j <= k; ++j)
        {
            if(i - j == 0)break;
            f[i] = min(f[i] , f[i-j] + abs(h[i-j] - h[i]));
        }
    }
    cout << f[n];
    return 0;
}
