#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    cin >> n;
    for (char &i : n)
    {
        if (i == '1')
            i = 9;
        else if (i == '9')
            i = 1;
    }
    int ans = n[0] * 100 + n[1] * 10 + n[2];
    cout << ans << endl;
}