#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int N, x;
    cin >> N >> x;

    int ans;
    if (N == 1)
    {
        ans = 1;
    }
    else if (N == 2)
    {
        if (x == 1)
            ans = 2;
        else
            ans = 1;
    }
    else
    {
        ans = N - x + 1;
    }
    cout << ans << endl;
    return (0);
}