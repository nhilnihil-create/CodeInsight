#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, res = 0, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        while(x % 2 == 0)
        {
            x /= 2;
            res++;
        }
    }
    cout << res << endl;
}