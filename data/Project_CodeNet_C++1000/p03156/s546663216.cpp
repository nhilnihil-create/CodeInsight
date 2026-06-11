#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    int count[3] = {};
    for(int i = 0;i < n;i++)
    {
        int p;
        cin >> p;
        if(p <= a)
        {
            count[0]++;
        }
        else if(p > b)
        {
            count[1]++;
        }
        else
        {
            count[2]++;
        }
    }
    int ans = 100000;
    for(int i = 0;i < 3;i++)
    {
        ans = min(ans,count[i]);
    }
    cout << ans << "\n";
    
    return 0;
}