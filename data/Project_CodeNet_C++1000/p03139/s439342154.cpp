#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    cout << min(a,b) << " ";
    if(a + b > n)
    {
        cout << a + b - n << "\n";
    }
    else
    {
        cout << "0\n";
    }
    
    return 0;
}