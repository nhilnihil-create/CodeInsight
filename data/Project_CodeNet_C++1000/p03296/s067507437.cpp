#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        if(i > 0 && a[i] == a[i - 1])
        {
            ans++;
            a[i] = -1;
        }
    }
    cout << ans << "\n";
    
    return 0;
}