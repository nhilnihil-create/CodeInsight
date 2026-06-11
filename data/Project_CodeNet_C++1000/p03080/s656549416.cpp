#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int n, r = 0, b = 0;
    cin >> n;
    string s;
    cin >> s;
    rep(i, n)
    {
        if (s[i] == 'R')
            r++;
        else
            b++;
    }
    if (r > b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
