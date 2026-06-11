#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    int a[n];
    double ave = 0,Min = 100000.0;
    int ans;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;
    for(int i = 0;i < n;i++)
    {
        if(fabs(ave - a[i]) < Min)
        {
            Min = fabs(ave - a[i]);
            ans = i;
        }
    }
    cout << ans << "\n";

    return 0;
}