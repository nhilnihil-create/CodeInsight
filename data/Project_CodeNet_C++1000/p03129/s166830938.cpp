#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    if(k > ceil(n / 2.0))
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
    
    return 0;
}