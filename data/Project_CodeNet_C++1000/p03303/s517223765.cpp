#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    string s;
    int w;
    cin >> s >> w;
    for(int i = 0;i < s.size();i++)
    {
        if(i % w == 0)
        {
            cout << s[i];
        }
    }
    cout << "\n";

    return 0;
}