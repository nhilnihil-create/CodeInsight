#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    int n;
    string a,b,c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i] == b[i] && b[i] == c[i])
        {
            continue;
        }
        else if(a[i] != b[i] && b[i] != c[i] && a[i] != c[i])
        {
            ans += 2;
        }
        else if(a[i] == b[i] && b[i] != c[i] || a[i] != b[i] && b[i] == c[i] || a[i] == c[i] && a[i] != b[i])
        {
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}