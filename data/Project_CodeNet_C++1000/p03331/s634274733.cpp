#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n, ans = 0;
    cin >> n;
    string str = to_string(n);
    for (unsigned int i = 0; i < str.length(); i++)
        ans += str[i] - 48;
    if (ans == 1)   
        cout << 10;
    else
        cout << ans;
    cout << endl;
}