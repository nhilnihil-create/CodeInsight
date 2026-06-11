#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int t[4] = {};
    for(int i = 0;i < 3;i++)
    {
        int a,b;
        cin >> a >> b;
        t[a - 1]++;
        t[b - 1] ++;
    }
    for(int i = 0;i < 4;i++)
    {
        if(t[i] == 0 || t[i] > 2)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}