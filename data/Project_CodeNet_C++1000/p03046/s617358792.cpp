#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , k;
    cin >> n >> k;
    int p = pow(2 , n) - 1;
    if(n == 1 && k == 1)
    {
        cout << -1;
        return 0;
    }
    if(p < k)
    {
        cout << -1;
        return 0;
    }
    if(k == 0)
    {
        for(int i = 0; i <= p; i ++)
            cout << i << ' ' << i << ' ';
        return 0;
    }
    cout << 0 << ' ' << k << ' ' << 0 << ' ';
    for(int i = 1; i <= p; i ++)
    {
        if(i != k)
            cout << i << ' ';

    }
    cout << k << ' ';
    for(int i = p; i >= 1; i --)
    {
        if(i != k)
            cout << i << ' ';
    }
    return 0;
}
