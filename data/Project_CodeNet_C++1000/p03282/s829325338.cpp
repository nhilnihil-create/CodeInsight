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
    string s;
    ll k;
    cin >> s >> k;
    ll first_not1 = 1000000000000000000;
    int num = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] != '1')
        {
            first_not1 = i;
            num = s[i] - '0';
            break;
        }
    }
    if (k <= first_not1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << num << endl;
    }

    return 0;
}