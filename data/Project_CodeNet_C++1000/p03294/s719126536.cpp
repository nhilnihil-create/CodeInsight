#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int a;
    int ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin>>a;
        ans += a - 1;
    }
    cout << ans << endl;
    return 0;
}