#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define debug(x) cerr << #x << ": " << x << '\n'

int main()
{
    ll N;
    string s;
    cin >> N >> s;
    int r = 0, b = 0;
    for (char c : s)
    {
        if (c == 'R')
        {
            ++r;
        }
        else
        {
            ++b;
        }
    }
    cout << (r > b ? "Yes" : "No") << endl;
}
