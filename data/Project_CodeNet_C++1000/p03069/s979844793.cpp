#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    int black[n + 1] = {},white[n + 1] = {};
    for(int i = 0;i < n;i++)
    {
        if(s[i] == '#')
        {
            black[i + 1] = black[i] + 1;
            white[i + 1] = white[i];
        }
        else
        {
            black[i + 1] = black[i];
            white[i + 1] = white[i] + 1;
        }
    }
    int ans = INT_MAX;
    for(int i = 0;i < n + 1;i++)
    {
        int temp = (black[i] - black[0]) + (white[n] - white[i]);
        if(temp < ans)
        {
            ans = temp;
        }
    }
    cout << ans << "\n";
    
    return 0;
}