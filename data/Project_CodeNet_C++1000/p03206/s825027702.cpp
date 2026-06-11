#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d;
    cin >> d;

    string ans;
    switch (d)
    {
    case 22:
        ans = "Christmas Eve Eve Eve";
        break;
    case 23:
        ans = "Christmas Eve Eve";
        break;
    case 24:
        ans = "Christmas Eve";
        break;
    default:
        ans = "Christmas";
        break;
    }

    cout << ans << endl;
}