#include <bits/stdc++.h>
// #define int long long 
using namespace std;

int main()
{
    long long m,k;
    cin >> m >> k;
    if(k >= 1 << m || (m == 1 && k == 1))
    {
        cout << (-1) << endl;
        return 0;
    }
    if(k == 0 && m == 1)
    {
        cout << "1 1 0 0\n";
        return 0;
    }
    int p = 1 << m;
    for(int i = 0; i < p; i++)
    {
        if(i != k)
        {
            cout << i << " ";
        }
    }
    cout << k << " ";
    for(int i = p - 1; i >= 0; i--)
    {
        if(i != k)
        {
            cout << i << " ";
        }
    }
    cout << k << endl;
}