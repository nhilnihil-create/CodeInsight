#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    bool flag[4] = {};
    for(int i = 0;i < 4;i++)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            flag[0] = true;
        }
        else if(n == 9)
        {
            flag[1] = true;
        }
        else if(n == 7)
        {
            flag[2] = true;
        }
        else if(n == 4)
        {
            flag [3] = true;
        }
    }
    for(int i = 0;i < 4;i++)
    {
        if(!flag[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}