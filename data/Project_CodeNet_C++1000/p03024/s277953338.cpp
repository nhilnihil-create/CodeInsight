#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == 'o')
        {
            count++;
        }
    }
    if(count + (15 - s.size()) >= 8)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    
    return 0;
}