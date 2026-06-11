#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{   
    string n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i < n.size();i++)
    {
        if(n[i] == '2')
        {
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}