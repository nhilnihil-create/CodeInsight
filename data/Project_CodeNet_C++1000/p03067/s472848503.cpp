#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a < c && c < b || b < c && c < a)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    
    return 0;
}