#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    int n, x[101], y[101], h[101];
    int flag = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i] >> h[i];
        if(h[i] != 0)
            flag = i;
    }

    int i,j,H;
    for(i = 0; i <= 100; ++i)
    {
        for(j = 0; j <= 100; ++j)
        {
            H = abs(x[flag] - i) + abs(y[flag] - j) + h[flag];
            for(int k = 0; k < n; ++k)
            {
                if(h[k] != max((H - abs(x[k] - i) - abs(y[k] - j)), 0))
                    break;
                if(k == n-1)
                {
                    cout << i << " " << j << " " << H << endl;
                }
            }
        }
    }
}