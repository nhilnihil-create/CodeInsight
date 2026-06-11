#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;

string s;
int c1, c2, ans, n;

int main()
{
    cin >> n >> s; ans = n;
    for (int i = 0; i < n; i++) c2 += (s[i] == '.');
    ans = min(ans, c1 + c2);
    for (int i = 0; i < n; i++)
    {
        c1 += (s[i] == '#');
        c2 -= (s[i] == '.');
        ans = min(ans, c1 + c2);
    }
    cout << ans;
}
