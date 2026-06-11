#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string ans;
    if (abs(a - b) <= d && abs(b - c) <= d)
    {
        ans = "Yes";
    }
    else if (abs(a - c) <= d)
    {
        ans = "Yes";
    }
    else
    {
        ans = "No";
    }
    cout << ans << endl;
    return (0);
}